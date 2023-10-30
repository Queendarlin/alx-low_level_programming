#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>


#define BUFSIZE 1024

void check_elf(unsigned char);
void print_magic(unsigned char);
void print_class(unsigned char);
void print_data(unsigned char);
void print_version(unsigned char);
void print_abi(unsigned char);
void print_osabi(unsigned char);
void print_type(unsigned int, unsigned char);
void print_entry(unsigned long int, unsigned char);
void close_elf(int);

char *create_buff(char *filename);
void close_fd(int file_D);

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif
