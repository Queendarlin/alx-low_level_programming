#include "main.h"

/**
 * print_error - Print an error message to stderr and exit with code 98
 * @message: The error message to print
 * Return: void
 */
void print_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

/**
 * print_elf_header_info - Print information from the ELF header
 * @header: A pointer to the ELF header
 * Return: void
 */
void print_elf_header_info(Elf64_Ehdr *header)
{
	int i;

	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("Class:   %d-bit\n",
			(header->e_ident[EI_CLASS] == ELFCLASS32) ? 32 : 64);

	printf("Data:    %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB)
			? "2's complement, little-endian" : "2's complement, big-endian");

	printf("Version: %d\n", header->e_ident[EI_VERSION]);

	printf("OS/ABI:  %d\n", header->e_ident[EI_OSABI]);

	printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

	printf("Type:    %d\n", header->e_type);

	printf("Entry point address: 0x%lx\n", header->e_entry);
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	const char *elf_filename;
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	elf_filename = argv[1];
	fd = open(elf_filename, O_RDONLY);

	if (fd == -1)
	{
		print_error("Error opening the file");
	}

	if (read(fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		print_error("Error reading ELF header");
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1]
			!= ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
	{
		print_error("Not an ELF file");
	}

	print_elf_header_info(&header);

	close(fd);
	return (0);
}
