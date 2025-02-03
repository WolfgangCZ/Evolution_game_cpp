#!/bin/sh

set -xe

gcc -g main.c -o main -I./raylib/ -L./raylib/ -lraylib -lm -lpthread -ldl -lrt

