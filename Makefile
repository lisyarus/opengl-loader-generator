test: test.cpp gl.hpp gl.cpp
	g++ test.cpp gl.cpp -o test -lGLX -lSDL2

gl.hpp gl.cpp: config.json generate.py
	./generate.py config.json
