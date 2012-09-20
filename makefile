CC=g++
CFLAGS=-Wall -Wextra -pedantic

all: softedge

softedge:
	$(CC) $(CFLAGS) -o softedge \
	-I "src/" \
	src/*.cpp src/renderer/*.cpp src/geometry/*.cpp src/examples/application.cpp \
	-lX11 -lGL -lGLU

softedge-assimp:
	$(CC) $(CFLAGS) -o "softedge-assimp" \
	-I "src/" \
	src/*.cpp src/renderer/*.cpp src/geometry/*.cpp src/examples/assimp.cpp \
	-lX11 -lGL -lGLU -lassimp

softedge-prof:
	$(CC) $(CFLAGS) -o "softedge-prof" \
	-pg \
	-I "src/" \
	src/*.cpp src/renderer/*.cpp src/geometry/*.cpp src/examples/assimp.cpp \
	-lX11 -lGL -lGLU -lassimp
