# A Makefile that performs both a make build as well as a make clean. Make build should be the
# first target. Note that you will have four executables.

FILES = Starter.c Fibb.c Prime.c Total.c
CC = gcc
OUT_EXE = Starter
SUBMIT_EXE = Elita-Danilyuk-HW2

build:
	$(CC) -g -Wall Starter.c -o $(OUT_EXE)
	$(CC) -g -Wall Fibb.c -o Fibb
	$(CC) -g -Wall Prime.c -o Prime
	$(CC) -g -Wall Total.c -o Total
package:
	tar cvzf $(SUBMIT_EXE).tar $(FILES) Makefile
clean:
	rm -f $(OUT_EXE) Fibb Prime Total $(SUBMIT_EXE).tar mem