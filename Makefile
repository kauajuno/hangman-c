all: Hangman

Hangman: hangman.h hangman.c main.c
	gcc -o Hangman hangman.c main.c

clean:
	rm -f Hangman

run: Hangman
	./Hangman