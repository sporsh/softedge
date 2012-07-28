CC=g++
CFLAGS=-Wall -Wextra -pedantic

all: softedge

softedge:
	$(CC) $(CFLAGS) -o softedge -lX11 -lGL -lGLU -I "src/" src/*.cpp src/renderer/*.cpp src/geometry/*.cpp src/examples/application.cpp

softedge-assimp:
	$(CC) $(CFLAGS) -o "softedge-assimp" -lX11 -lGL -lGLU -lassimp -I "src/" src/*.cpp src/renderer/*.cpp src/geometry/*.cpp src/examples/assimp.cpp

softedge-prof:
	$(CC) $(CFLAGS) -o "softedge-prof" -lX11 -lGL -lGLU -lassimp -pg -I "src/" src/*.cpp src/renderer/*.cpp src/geometry/*.cpp src/examples/assimp.cpp