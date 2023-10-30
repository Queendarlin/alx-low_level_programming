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

void fileCheck_elf(unsigned char *elf_mgcNum);
void elf_magic(unsigned char *elf_mgcNum);
void elf_class(unsigned char *elf_mgcNum);
void elf_data(unsigned char *elf_mgcNum);
void elf_version(unsigned char *elf_mgcNum);
void elf_OSAB(unsigned char *elf_mgcNum);
void elf_ABI(unsigned char *elf_mgcNum);
void elf_type(unsigned int type_elf, unsigned char *elf_mgcNum);
void elf_entry(unsigned long int addr_entry, unsigned char *elf_mgcNum);
void fileClose_elf(int file_open);
int main(int __attribute__((__unused__)) argc, char *argv[]);

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif
