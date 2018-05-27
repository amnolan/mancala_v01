# -*- MAKEFILE -*-

mancala: mancala.o print_and_io.o game_logic.o check_logic.o
	gcc -o mancala mancala.o print_and_io.o game_logic.o check_logic.o

print_and_io.o: print_and_io.c libraries.h
	gcc -c print_and_io.c

game_logic.o: game_logic.c libraries.h
	gcc -c game_logic.c

check_logic.o: check_logic.c libraries.h
	gcc -c check_logic.c
