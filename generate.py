#!/usr/bin/env python3

import sys
import json

# Default config

class Object(object):
    pass

default_config = Object()

default_config.spec_file = 'gl.xml'
default_config.api = 'gl'
default_config.version = '4.6'
default_config.profile = 'core'
default_config.extensions = []

default_config.indent = "\t"
default_config.namespace = 'gl'
default_config.loader_namespace = 'sys'
default_config.internal_namespace = 'internal'
default_config.internal_prefix = ''

default_config.undef = 4
default_config.strip = True

default_config.out_header = 'gl.hpp'
default_config.out_source = 'gl.cpp'
default_config.include = '"gl.hpp"'

# Parse config

if len(sys.argv) != 2:
	print("Usage: {} <config-file-json>".format(sys.argv[0]))
	sys.exit(1)

cfg = json.load(open(sys.argv[1], 'rt'))

config = Object()

config.spec_file  = cfg.get('spec_file',  default_config.spec_file)
config.api        = cfg.get('api',        default_config.api      )
config.version    = cfg.get('version',    default_config.version  )
config.profile    = cfg.get('profile',    default_config.profile  )
config.extensions = cfg.get('extensions', default_config.extensions)

config.indent             = cfg.get('indent',             default_config.indent            )
config.namespace          = cfg.get('namespace',          default_config.namespace         )
config.loader_namespace   = cfg.get('loader_namespace',   default_config.loader_namespace  )
config.internal_namespace = cfg.get('internal_namespace', default_config.internal_namespace)
config.internal_prefix    = cfg.get('internal_prefix',    default_config.internal_prefix   )

config.undef = cfg.get('undef', default_config.undef)
config.strip = cfg.get('strip', default_config.strip)

config.out_header = cfg.get('out_header', default_config.out_header)
config.out_source = cfg.get('out_source', default_config.out_source)
config.include    = cfg.get('include',    "\"{}\"".format(config.out_header))

# Helper variables & functions

api_name = {
    'gl': "OpenGL",
    'gles1': "OpenGL ES",
    'gles2': "OpenGL ES",
    'glsc2': "OpenGL SC",
}

if config.api not in api_name:
    print('Unknown api:', config.api)
    sys.exit(1)

indent = config.indent
gl_indent = indent
int_indent = indent
sys_indent = indent

if not config.namespace:
    gl_indent = ""

if not config.internal_namespace:
    int_indent = ""

if not config.loader_namespace:
    sys_indent = ""

def strip(name):
    if config.strip:
        if name[:3] == 'GL_': return name[3:]
        if name[:2] == 'gl': return name[2:]
    return name

def parse_name_and_type(node, need_strip):
    nptype = node.find('ptype')
    nname = node.find('name')

    name = nname.text

    proto = ""
    if node.text:
        proto += node.text
    if nptype is not None:
        proto += nptype.text
        if nptype.tail:
            proto += nptype.tail
    proto += strip(nname.text) if need_strip else nname.text
    if nname.tail:
        proto += nname.tail

    t = ""
    if node.text:
        t += node.text
    if nptype is not None:
        t += nptype.text
        if nptype.tail:
            t += nptype.tail

    return (name, proto, t)
    
def internal_name(name, ns):
    return ((config.internal_namespace + "::") if (config.internal_namespace and ns) else "") + config.internal_prefix + name

def valid_id(name):
    return not name[0].isnumeric()

# Parse the spec

import xml.etree.ElementTree as ET
root = ET.parse(config.spec_file).getroot()

types = []
for ntypes in root.findall('types'):
    for ntype in ntypes.findall('type'):
        nname = ntype.find('name')

        t = ""
        if ntype.text:
            t += ntype.text
        if nname is not None:
            if nname.text:
                t += nname.text
            if nname.tail:
                t += nname.tail

        types.append(t)

enums = {}
for nenums in root.findall('enums'):
    if nenums.get('namespace') != 'GL': continue

    for nenum in nenums.findall('enum'):
        name = nenum.get('name')
        value = nenum.get('value')
        t = nenum.get('type')

        enums[name] = {}
        enums[name]['value'] = value
        enums[name]['type'] = 'GLenum'
        if t is not None:
            if t == 'u':
                enums[name]['type'] = 'unsigned'
            if t == 'ull':
                enums[name]['type'] = 'unsigned long long'

commands = {}
for ncommands in root.findall('commands'):
    if ncommands.get('namespace') != 'GL': continue

    for ncommand in ncommands.findall('command'):
        name, proto, t = parse_name_and_type(ncommand.find('proto'), config.strip)

        params = []
        for nparam in ncommand.findall('param'):
            params.append(parse_name_and_type(nparam, False))

        commands[name] = {}
        commands[name]['proto'] = proto
        commands[name]['type'] = t
        commands[name]['params'] = params

def process_features(node):
    result = {
        'enums': [],
        'commands': []
    }
    for nrequire in node.findall('require'):
        profile = nrequire.get('profile')
        if profile is not None and config.profile is not None and profile != config.profile: continue
        for nenum in nrequire.findall('enum'):
            result['enums'].append(nenum.get('name'))
        for ncommand in nrequire.findall('command'):
            result['commands'].append(ncommand.get('name'))
    
    removed = set()
    for nremove in node.findall('remove'):
        profile = nremove.get('profile')
        if profile is not None and config.profile is not None and profile != config.profile: continue
        for nenum in nremove.findall('enum'):
            removed.add(nenum.get('name'))
        for ncommand in nremove.findall('command'):
            removed.add(ncommand.get('name'))

    return (result, removed)

api_by_version = {}
api_by_extension = {}
removed = set()

for nfeature in root.findall('feature'):
    api = nfeature.get('api')
    version = nfeature.get('number')
    if api != config.api or version is None or version > config.version: continue
    f, r = process_features(nfeature)
    api_by_version[version] = f
    removed = removed.union(r)

for nextension in root.find('extensions').findall('extension'):
    name = nextension.get('name')
    if name[3:] not in config.extensions: continue
    f, r = process_features(nextension)
    api_by_extension[name] = f

# Write the header file

header_definitions = """
// Prevent inclusion of other OpenGL-related headers

#if defined(__glew_h__) || defined(__GLEW_H__)
#error Attempt to include auto-generated header after including glew.h
#endif
#if defined(__gl_h_) || defined(__GL_H__)
#error Attempt to include auto-generated header after including gl.h
#endif
#if defined(__glext_h_) || defined(__GLEXT_H_)
#error Attempt to include auto-generated header after including glext.h
#endif
#if defined(__gltypes_h_)
#error Attempt to include auto-generated header after gltypes.h
#endif
#if defined(__gl_ATI_h_)
#error Attempt to include auto-generated header after including glATI.h
#endif

#define __glew_h__
#define __GLEW_H__
#define __gl_h_
#define __GL_H__
#define __glext_h_
#define __GLEXT_H_
#define __gltypes_h_
#define __gl_ATI_h_

"""

with open(config.out_header, 'wt') as header:

    pointers_defined = set()
    enums_defined = set()
    functions_defined = set()

    header.write("#pragma once\n")
    header.write(header_definitions)

    # Write undefs
    if config.undef > 0:
        header.write("// Undefine some macros that may interfere with {} constants\n\n".format(api_name[config.api]))
        for e in enums:
            name = strip(e)
            if valid_id(name) and len(name) <= config.undef:
                header.write("#undef {}\n".format(name))
        header.write("\n")

    # Write type definitions
    header.write("// {} type definitions\n\n".format(api_name[config.api]))
    for t in types:
        header.write(t + "\n")
    header.write("\n")

    if config.namespace:
        header.write("namespace {}\n{{\n\n".format(config.namespace))

    # Write internal pointers
    if config.internal_namespace:
        header.write("{}namespace {}\n{}{{\n\n".format(gl_indent, config.internal_namespace, gl_indent))

    def internal_write_features(f):
        for c in f['commands']:
            if c in pointers_defined: continue
            if c in removed: continue
            pointers_defined.add(c)
            command = commands[c]

            proto = command['proto'].replace(strip(c), "(*" + internal_name(c, False) + ")")
            params_proto = ", ".join(p[1] for p in command['params'])

            header.write("{}{}extern {}({});\n".format(gl_indent, int_indent, proto, params_proto))
        header.write("\n")

    for version in sorted(api_by_version.keys()):
        header.write("{}{}// {} {}\n\n".format(gl_indent, int_indent, api_name[config.api], version))
        internal_write_features(api_by_version[version])

    for name in api_by_extension.keys():
        header.write("{}{}// {}\n\n".format(gl_indent, int_indent, name))
        internal_write_features(api_by_extension[name])

    if config.internal_namespace:
        header.write("{}}} // namespace {}\n\n".format(gl_indent, config.internal_namespace))
        
    # Write enums & inline functions
    def write_features(f):
        for e in f['enums']:
            if e in enums_defined: continue
            if e in removed: continue
            enums_defined.add(e)

            name = strip(e) 
            if not valid_id(name):
                name = "_" + name
            header.write("{}constexpr {} {} = {};\n".format(gl_indent, enums[e]['type'], name, enums[e]['value']))
        header.write("\n")
        for c in f['commands']:
            if c in functions_defined: continue
            if c in removed: continue
            functions_defined.add(c)
            command = commands[c]

            proto = command['proto']
            pointer_name = internal_name(c, True)
            params = ", ".join(p[0] for p in command['params'])
            params_proto = ", ".join(p[1] for p in command['params'])

            header.write("{}inline {}({}){{ return {}({}); }}\n".format(gl_indent, proto, params_proto, pointer_name, params))
        header.write("\n")

    for version in sorted(api_by_version.keys()):
        header.write("{}// {} {}\n\n".format(gl_indent, api_name[config.api], version))
        write_features(api_by_version[version])

    for name in api_by_extension.keys():
        header.write("{}// {}\n\n".format(gl_indent, name))
        write_features(api_by_extension[name])

    if config.loader_namespace:
        header.write("{}namespace {}\n{}{{\n\n".format(gl_indent, config.loader_namespace, indent))

    header.write("{}{}bool initialize();\n".format(gl_indent, sys_indent))
    header.write("{}{}const char * api();\n".format(gl_indent, sys_indent))
    header.write("{}{}int major_version();\n".format(gl_indent, sys_indent))
    header.write("{}{}int minor_version();\n".format(gl_indent, sys_indent))
    header.write("\n")

    for name in api_by_extension.keys():
        header.write("{}{}bool ext_{}();\n".format(gl_indent, sys_indent, name[3:]))
    header.write("\n")

    if config.loader_namespace:
        header.write("{}}} // namespace {}\n\n".format(gl_indent, config.loader_namespace))

    if config.namespace:
        header.write("}} // namespace {}\n\n".format(config.namespace))

# Write the source file

source_definitions = """
#include <unordered_set>
#include <string>

#if defined(__APPLE__)
#include <dlfcn.h>
#elif defined(__sgi) || defined (__sun)
#include <dlfcn.h>
#include <stdio.h>
#elif defined(_WIN32)
#include <windows.h>
#else
#include <GL/glx.h>
#endif

"""

get_proc_address_code = """
#if defined(__APPLE__)

static void * get_proc_address(const char *func)
{
\tstatic void * image = dlopen("/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL", RTLD_LAZY);

\tif (!image) return nullptr;

\treturn dlsym(image, func);
}

#elif defined(__sgi) || defined (__sun)

static void * get_proc_address(const char *func)
{
\tstatic void * image = dlopen(nullptr, RTLD_LAZY | RTLD_LOCAL);
\tstatic void * gpa = image ? dlsym(image, "glXGetProcAddress") : nullptr;

\tif (gpa)
\t\treturn reinterpret_cast<void(*)(const GLubyte*)>(gpa)(reinterpret_cast<const char *>(name));
\telse
\t\treturn dlsym(image, name);
}

#elif defined(_WIN32)

#ifdef _MSC_VER
#pragma warning(disable: 4055)
#pragma warning(disable: 4054)
#pragma warning(disable: 4996)
#endif

static int test_pointer(const PROC p)
{
\tptrdiff_t i;
\tif (!p) return 0;
\ti = (ptrdiff_t)p;

\tif(i == 1 || i == 2 || i == 3 || i == -1) return 0;

\treturn 1;
}

static void * get_proc_address(const char *name)
{
\tstatic HMODULE image = GetModuleHandleA("opengl32.dll");

\tPROC func = wglGetProcAddress(reinterpret_cast<LPCSTR>(name));
\tif (test_pointer(func))
\t{
\t\treturn reinterpret_cast<void*>(func);
\t}

\treturn reinterpret_cast<void*>(GetProcAddress(image, reinterpret_cast<LPCSTR>(name)));
}
	
#else // GLX

static void * get_proc_address(const char *func)
{
\treturn reinterpret_cast<void *>(glXGetProcAddress(reinterpret_cast<const GLubyte*>(func)));
}

#endif
"""

with open(config.out_source, 'wt') as source:

    source.write("#include {}\n\n".format(config.include))

    source.write(source_definitions)

    if config.namespace:
        source.write("namespace {}\n{{\n\n".format(config.namespace))

    # Write internal pointers
    pointers_defined = set()

    if config.internal_namespace:
        source.write("{}namespace {}\n{}{{\n\n".format(gl_indent, config.internal_namespace, indent))

    for line in get_proc_address_code.splitlines():
        source.write(gl_indent + int_indent + line.replace("\t", indent) + "\n")
    source.write("\n")

    def internal_write_features(f):
        for c in f['commands']:
            if c in pointers_defined: continue
            if c in removed: continue
            pointers_defined.add(c)
            command = commands[c]

            proto = command['proto'].replace(strip(c), "(*" + internal_name(c, False) + ")")
            params_proto = ", ".join(p[1] for p in command['params'])

            source.write("{}{}{}({}) = nullptr;\n".format(gl_indent, int_indent, proto, params_proto))
        source.write("\n")

    for version in sorted(api_by_version.keys()):
        source.write("{}{}// {} {}\n\n".format(gl_indent, int_indent, api_name[config.api], version))
        internal_write_features(api_by_version[version])

    for name in api_by_extension.keys():
        source.write("{}{}// {}\n\n".format(gl_indent, int_indent, name))
        internal_write_features(api_by_extension[name])

    if config.internal_namespace:
        source.write("{}}} // namespace {}\n\n".format(gl_indent, config.internal_namespace))

    pointers_defined = set()

    if config.loader_namespace:
        source.write("{}namespace {}\n{}{{\n\n".format(gl_indent, config.loader_namespace, indent))

    for name in api_by_extension.keys():
        source.write("{}{}static bool ext_{}_loaded = false;\n".format(gl_indent, int_indent, name))
    source.write("\n")

    def write_loaders(f):
        for c in f['commands']:
            if c in pointers_defined: continue
            if c in removed: continue
            pointers_defined.add(c)

            command = commands[c]

            params_proto = ", ".join(p[2] for p in command['params'])

            source.write("{}{}{}{} = reinterpret_cast<{}(*)({})>({}(\"{}\"));\n".format(gl_indent, sys_indent, indent, internal_name(c, True),
                command['type'], params_proto, internal_name('get_proc_address', True), c))
            source.write("{}{}{}if (!{}) return false;\n".format(gl_indent, sys_indent, indent, internal_name(c, True)))


    source.write("{}{}static bool load_core()\n".format(gl_indent, sys_indent))
    source.write("{}{}{{\n".format(gl_indent, sys_indent))
    for version in sorted(api_by_version.keys()):
        source.write("{}{}{}// {} {}\n\n".format(gl_indent, sys_indent, indent, api_name[config.api], version))
        write_loaders(api_by_version[version])
        source.write("\n")
    source.write("{}{}{}return true;\n".format(gl_indent, sys_indent, indent))
    source.write("{}{}}}\n\n".format(gl_indent, sys_indent))

    for name in api_by_extension.keys():
        source.write("{}{}static bool load_ext_{}()\n".format(gl_indent, sys_indent, name))
        source.write("{}{}{{\n".format(gl_indent, sys_indent))
        write_loaders(api_by_extension[name])
        source.write("\n")
        source.write("{}{}{}return true;\n".format(gl_indent, sys_indent, indent))
        source.write("{}{}}}\n\n".format(gl_indent, sys_indent))

    source.write("{}{}static std::unordered_set<std::string> extensions;\n".format(gl_indent, sys_indent))

    source.write("{}{}bool initialize()\n".format(gl_indent, sys_indent))
    source.write("{}{}{{\n".format(gl_indent, sys_indent))
    source.write("{}{}{}if (!load_core()) return false;\n".format(gl_indent, sys_indent, indent))
    source.write("\n")
    source.write("{}{}{}GLint num_extensions;\n".format(gl_indent, sys_indent, indent))
    source.write("{}{}{}{}({}, &num_extensions);\n".format(gl_indent, sys_indent, indent, internal_name('glGetIntegerv', True), enums['GL_NUM_EXTENSIONS']['value']))
    source.write("{}{}{}for (GLint i = 0; i < num_extensions; ++i)\n".format(gl_indent, sys_indent, indent))
    source.write("{}{}{}{}extensions.insert(reinterpret_cast<const char *>({}({}, i)));\n".format(gl_indent, sys_indent, indent, indent, internal_name('glGetStringi', True), enums['GL_EXTENSIONS']['value']))
    source.write("\n")
    for name in api_by_extension.keys():
        source.write("{}{}{}if (extensions.count(\"{}\") > 0)\n".format(gl_indent, int_indent, indent, name))
        source.write("{}{}{}{}ext_{}_loaded = load_ext_{}();\n".format(gl_indent, int_indent, indent, indent, name, name))
    source.write("\n")
    source.write("{}{}{}return true;\n".format(gl_indent, sys_indent, indent))
    source.write("{}{}}}\n".format(gl_indent, sys_indent))
    source.write("\n")

    source.write("{}{}const char * api(){{ return \"{}\"; }}\n\n".format(gl_indent, sys_indent, api_name[config.api]))
    source.write("{}{}int major_version(){{ return {}; }}\n\n".format(gl_indent, sys_indent, config.version[0]))
    source.write("{}{}int minor_version(){{ return {}; }}\n\n".format(gl_indent, sys_indent, config.version[2]))

    for name in api_by_extension.keys():
        source.write("{}{}bool ext_{}(){{ return ext_{}_loaded; }}\n".format(gl_indent, int_indent, name[3:], name))
    source.write("\n")

    if config.loader_namespace:
        source.write("{}}} // namespace {}\n\n".format(gl_indent, config.loader_namespace))

    if config.namespace:
        source.write("}} // namespace {}\n\n".format(config.namespace))
