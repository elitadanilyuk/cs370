FILES = Starter.c Executor.c Executor.h
CC = gcc
OUT_EXE = Starter
SUBMIT_EXE = Elita-Danilyuk-HW1

build:
	$(CC) -g -Wall $(FILES) -o $(OUT_EXE)
package:
	tar cvzf $(SUBMIT_EXE).tar $(FILES) README.txt Makefile
clean:
	rm -f $(OUT_EXE) $(SUBMIT_EXE).tar mem