CC = gcc
CFLAGS = -Wall
INCLUDES = -I./raylib/
LIBS = -L./raylib
FLAGS = -lraylib -lm -lpthread -ldl -lrt 
TARGETS = main.c ./src/*

debug main.c:
	$(CC) $(CFLAGS) $(TARGETS) -o bin/main $(INCLUDES) $(LIBS) $(LIBS) $(FLAGS)
