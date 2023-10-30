#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

int open_source_file(const char *filename);
int open_destination_file(const char *filename);
int copy_file(int source_fd, int dest_fd);
int main(int argc, char *argv[]);


ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif
