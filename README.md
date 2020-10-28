# OpenGL Loader Generator

OpenGL Loader Generator is a generator of [OpenGL loading library](https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library) targetting C++ that supports different OpenGL versions, profiles, extensions, and even has adjustable code formatting. The generated library loads OpenGL function pointers & can be used in place of system-provided OpenGL header files (which [are known](https://www.khronos.org/opengl/wiki/Load_OpenGL_Functions#Function_Prototypes) to contain definitions for only a few extremely old OpenGL verions). The library has no dependencies other than an OpenGL implementation and a C++11 compiler.

The project has been tested under Linux with GCC 9.2 & under Windows with MinGW 9.3. If for some reason it doesn't work for your platform, be welcome to post an issue or (better) make a PR.

The project is heavily influenced by [glLoadGen](https://bitbucket.org/alfonse/glloadgen) (no longer supported).

# Generation

The generator itself is a single python script `generator.py`. It needs a configuration file to work, though.

To generate the loading library (header & source files), run
`./generator.py config.json` 

The config file is a single JSON object containing the generator configuration (see the [example file](https://github.com/lisyarus/opengl-loader-generator/blob/master/config.json)). A config file was chosen instead of e.g. command-line arguments to make updating the config & loader easier.

The following generator options are supported:

| Option | Type | Default value | Description |
| --- | --- | --- | --- |
| `spec_file` | `string` | `"gl.xml"` | Path to [OpenGL specification XML file](https://github.com/KhronosGroup/OpenGL-Registry/tree/master/xml) (a version of this file is included in this repository) |
| `api` | `string` | `"gl"` | The API to load: `gl`, `gles1`, `gles2` or `glsc` |
| `version` | `string` | `"4.6"` | The API version to load |
| `profile` | `string` | `"core"` | The API profile to load (may be empty) |
| `extensions` | `[string]` | `[]` | The list of extensions to load |
| `indent` | `string` | `"\t"` | The string to use as indentation in the generated code |
| `namespace` | `string` | `"gl"` | The namespace that will be used for generated API functions and constant (empty namespace means using global namespace) |
| `loader_namespace` | `string` | `"sys"` | The namespace that will be used for the loader library public functions, relative to the `gl` namespace (empty namespace means using parent namespace) |
| `internal_namespace` | `string` | `"internal"` | The namespace that will be used for the loader library internals, relative to the `gl` namespace (empty namespace means using parent namespace) |
| `internal_prefix` | `string` | `""` | The prefix that will be appended to all OpenGL function names in the loader library internals (**not** the loaded OpenGL functions) |
| `undef` | `int` | `4` | All OpenGL constants of this length or shorter will be `#undef`ined in the beginning of the library header (some systems may define `TRUE`, `ZERO`, etc) |
| `strip` | `bool` | `true` | Whether to strip the `gl` and `GL_` prefixes from OpenGL functions and constants (makes sense when using a namespace) |
| `out_header` | `string` | `"gl.hpp"` | The path to the generated loader library header |
| `out_source` | `string` | `"gl.cpp"` | The path to the generated loader library source |
| `include` | `string` | `"\"${config.out_header}\""` | The string to be used by the library source to include the library header (including the `""` or `<>`); that is, the library source will contain a line `#include ${config.include}` |

All non-absolute paths are resolved relative to current working directory.

The generated functions are in C++, thus adhere to C++ linkage & name mangling rules.

Note that with `config.namespace = ""` and `config.strip = false` make the generated functions appear in the global namespace with names identical to how they are defined in OpenGL (e.g. `glClear` in the global namespace, etc). This may interfere with already existing OpenGL functions, use at your own risk (however the library prevents including OpenGL headers alongside itself, and OpenGL functions have `C` linkage, so it should be hard to actually face any problems).

See the examples of generated [header](https://github.com/lisyarus/opengl-loader-generator/blob/master/gl.hpp) and [source](https://github.com/lisyarus/opengl-loader-generator/blob/master/gl.cpp) for further details on the structure of the generated files.

# Usage

With the default settings, the `gl` namespace contains all OpenGL functions and constants for a particular version & profile, while the loader library API is in the `gl::sys` namespace. The `gl::internal` namespace will contain the actual OpenGL functions' pointers that will be loaded at runtime. All of these namespaces can be changed through the configuration file.

To initialize the library, call `gl::sys::initialize()`. This function returns `true` if all the required OpenGL functions were successfully loaded (excluding extensions), and `false` otherwise. To check if a particular requested extension is supported, call `gl::sys::ext_EXTENSION_NAME()`, e.g. `gl::sys::ext_ARB_texture_filter_anisotropic()` for the `GL_ARB_texture_filter_anisotropic` extension (note that the `GL_` part is stripped).

The loaded functions and constants can be used like `gl::DrawArrays(gl::TRIANGLES, 0, 6)` (again, assuming default settings). See the [test application](https://github.com/lisyarus/opengl-loader-generator/blob/master/test.cpp) for a working example of library usage.

# License

The OpenGL Loader Generator is distributed under the [MIT license](https://github.com/lisyarus/opengl-loader-generator/blob/master/LICENSE).

# Contributing

Any fixes and/or enhancements are **warmly welcome**.
Before creating a pull request, make sure that the [test application](https://github.com/lisyarus/opengl-loader-generator/blob/master/Makefile) compiles and runs successfully (you'll need the [SDL2 library](https://www.libsdl.org/download-2.0.php) for that).