
CC=g++
SDL2CFG= --cflags --libs
CCFLAGS= -std=c11 -O2 -g -Wall

objects=obj/ekans.o obj/game.o obj/snake.o
source=src/ekans.cpp src/game.cpp src/snake.cpp

ekans: $(objects)
	$(CC) -o ekans $(objects) $(CCFLAGS) `sdl2-config --cflags --libs`

obj/ekans.o: src/ekans.cpp
	$(CC) -c src/ekans.cpp -o obj/ekans.o

obj/game.o: src/game.cpp
	$(CC) -c src/game.cpp -o obj/game.o

obj/snake.o: src/snake.cpp
	$(CC) -c src/snake.cpp -o obj/snake.o

clean:
	rm $(objects)



