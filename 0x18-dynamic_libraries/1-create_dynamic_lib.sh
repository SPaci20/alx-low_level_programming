#!/bin/bash

# Compile all .c files into object files
gcc -c -fPIC *.c

# Exclude _strncpy.o and create the dynamic library
gcc -shared -o liball.so \
    _putchar.o _islower.o _isalpha.o _abs.o _isupper.o \
    _isdigit.o _strlen.o _puts.o _atoi.o _strcat.o \
    _strncat.o _strcmp.o _memset.o _memcpy.o \
    _strchr.o _strspn.o _strpbrk.o _strstr.o

# Clean up object files
rm -f *.o
