
CC=g++
SDL2CFG= --cflags --libs
CCFLAGS= -std=c11 -O2 -g -Wall

objects=obj/ekans.o obj/game.o 
source=src/ekans.cpp src/game.cpp

ekans: $(objects)
	$(CC) -o ekans $(objects) $(CCFLAGS) `sdl2-config --cflags --libs`

obj/ekans.o: src/ekans.cpp
	$(CC) -c src/ekans.cpp -o obj/ekans.o

obj/game.o: src/game.cpp
	$(CC) -c src/game.cpp -o obj/game.o

clean:
	rm $(objects)



