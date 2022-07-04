# A Makefile that performs both a make build as well as a make clean. Make build should be the
# first target. Note that you will have four executables.

FILES = Starter.c CharacterReader.c Fibb.c Prime.c Total.c
CC = gcc
FLAGS = -lrt -g -Wall -Wextra -Wpedantic 
OUT_EXE = Starter
SUBMIT_EXE = HW3

build:
	$(CC) $(FLAGS) Starter.c -o $(OUT_EXE)
	$(CC) $(FLAGS) CharacterReader.c -o CharacterReader
	$(CC) $(FLAGS) Fibb.c -o Fibb
	$(CC) $(FLAGS) Prime.c -o Prime
	$(CC) $(FLAGS) Total.c -o Total
package:
	tar cvzf $(SUBMIT_EXE).tar $(FILES) Makefile
clean:
	rm -f $(OUT_EXE) CharacterReader Fibb Prime Total $(SUBMIT_EXE).tar mem