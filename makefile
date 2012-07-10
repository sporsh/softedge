CC=g++
CFLAGS=-Wall -Wextra -pedantic

all: softedge

softedge:
	$(CC) $(CFLAGS) -o softedge -lX11 -lGL -lGLU -I "src/" src/*.cpp src/renderer/*.cpp src/geometry/*.cpp src/examples/application.cpp
