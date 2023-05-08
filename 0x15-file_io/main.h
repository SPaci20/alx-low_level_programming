#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>


ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int cp(const char *file_from, const char *file_to);
void print_error(char *message);

#endif /* MAIN_H */
