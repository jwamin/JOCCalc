all: ccalc

CC = clang

WARNINGS = -Wall
DEBUG = -ggdb -fno-omit-frame-pointer
OPTIMIZE = -O2
LIBS = -lm

ccalc: Makefile main.c
	$(CC) -o $@ $(WARNINGS) $(DEBUG) $(OPTIMIZE) main.c jccalculator.c $(LIBS)

clean:
	rm -f ccalc

# Builder will call this to install the application before running.
install:
	echo "Installing is not supported"

# Builder uses this target to run your application.

asm: Makefile mazegen.cpp
	$(CC) -S main.c jccalculator.c

run:
	./ccalc

