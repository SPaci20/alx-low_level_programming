#!/bin/bash

#compile all .c files in the current directory
gcc -c *.c

#Create the static library
ar rcs liball.a *.o
