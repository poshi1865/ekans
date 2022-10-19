CC=g++
SDL2CFG= --cflags --libs
CCFLAGS= -O2 -g -Wall

source=src/ekans.cpp src/game.cpp src/snake.cpp

ekans: $(objects)
	$(CC) -o ekans $(source) $(CCFLAGS) `sdl2-config --cflags --libs`

