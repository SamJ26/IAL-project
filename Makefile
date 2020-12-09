CC = gcc
FLAGS = -Wall -Wextra -pedantic -Werror -std=c99


all: main


main: main.o hamPath.o graphLib.o cycle.o
	$(CC) $(FLAGS) $^ -o $@

main.o: main.c
	$(CC) $(FLAGS) -c $< -o $@

hamPath.o: hamPath.c hamPath.h
	$(CC) $(FLAGS) -c $< -o $@

graphLib.o: graphLib.c graphLib.h
	$(CC) $(FLAGS) -c $< -o $@

cycle.o: cycle.c cycle.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm main *.o