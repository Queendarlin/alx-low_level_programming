#include "main.h"

/**
 * fileCheck_elf - Checks if a file is a valid ELF file.
 * @elf_mgcNum: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not a valid ELF file, it exits with code 98.
 */
void fileCheck_elf(unsigned char *elf_mgcNum)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (elf_mgcNum[index] != 127 &&
				elf_mgcNum[index] != 'E' &&
				elf_mgcNum[index] != 'L' &&
				elf_mgcNum[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not a valid ELF file\n");
			exit(98);
		}
	}
}

/**
 * elf_magic - Prints the magic numbers of an ELF header.
 * @elf_mgcNum: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void elf_magic(unsigned char *elf_mgcNum)
{
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", elf_mgcNum[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * elf_class - Prints the ELF class of an ELF header.
 * @elf_mgcNum: A pointer to an array containing the ELF class.
 */
void elf_class(unsigned char *elf_mgcNum)
{
	printf(" Class: ");

	switch (elf_mgcNum[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_mgcNum[EI_CLASS]);
	}
}

/**
 * elf_data - Prints the data format of an ELF header.
 * @elf_mgcNum: A pointer to an array containing the ELF data format.
 */
void elf_data(unsigned char *elf_mgcNum)
{
	printf(" Data: ");

	switch (elf_mgcNum[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_mgcNum[EI_CLASS]);
	}
}

/**
 * elf_version - Prints the version of an ELF header.
 * @elf_mgcNum: A pointer to an array containing the ELF version.
 */
void elf_version(unsigned char *elf_mgcNum)
{
	printf(" Version: %d", elf_mgcNum[EI_VERSION]);

	switch (elf_mgcNum[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * elf_OSAB - Prints the operating system and ABI of an ELF header.
 * @elf_mgcNum: A pointer to an array containing the OS and ABI information.
 */
void elf_OSAB(unsigned char *elf_mgcNum)
{
	printf(" OS/ABI: ");

	switch (elf_mgcNum[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_mgcNum[EI_OSABI]);
	}
}

/**
 * elf_ABI - Prints the ABI version of an ELF header.
 * @elf_mgcNum: A pointer to an array containing the ABI version.
 */
void elf_ABI(unsigned char *elf_mgcNum)
{
	printf(" ABI Version: %d\n", elf_mgcNum[EI_ABIVERSION]);
}

/**
 * elf_type - Prints the type of an ELF header.
 * @type_elf: The ELF type.
 * @elf_mgcNum: A pointer to an array containing the ELF class.
 */
void elf_type(unsigned int type_elf, unsigned char *elf_mgcNum)
{
	if (elf_mgcNum[EI_DATA] == ELFDATA2MSB)
		type_elf >>= 8;

	printf(" Type: ");

	switch (type_elf)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", type_elf);
	}
}

/**
 * elf_entry - Prints the entry point address of an ELF header.
 * @addr_entry: The address of the ELF entry point.
 * @elf_mgcNum: A pointer to an array containing the ELF class.
 */
void elf_entry(unsigned long int addr_entry, unsigned char *elf_mgcNum)
{
	printf(" Entry point address: ");

	if (elf_mgcNum[EI_DATA] == ELFDATA2MSB)
	{
		addr_entry = ((addr_entry << 8) & 0xFF00FF00) |
			((addr_entry >> 8) & 0xFF00FF);
		addr_entry = (addr_entry << 16) | (addr_entry >> 16);
	}

	if (elf_mgcNum[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)addr_entry);
	else
		printf("%#lx\n", addr_entry);
}

/**
 * fileClose_elf - Closes an ELF file.
 * @file_open: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed, it exits with code 98.
 */
void fileClose_elf(int file_open)
{
	if (close(file_open) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close file descriptor %d\n", file_open);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not a valid ELF file or
 * the function fails, it exits with code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	int file_open, file_r;
	Elf64_Ehdr *elf_header;

	file_open = open(argv[1], O_RDONLY);
	if (file_open == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	elf_header = malloc(sizeof(Elf64_Ehdr));
	if (elf_header == NULL)
	{
		fileClose_elf(file_open);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	file_r = read(file_open, elf_header, sizeof(Elf64_Ehdr));			if (file_r == -1)
	{
		free(elf_header);
		fileClose_elf(file_open);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	fileCheck_elf(elf_header->e_ident);
	printf("ELF Header:\n");
	elf_magic(elf_header->e_ident);
	elf_class(elf_header->e_ident);
	elf_data(elf_header->e_ident);
	elf_version(elf_header->e_ident);
	elf_OSAB(elf_header->e_ident);
	elf_ABI(elf_header->e_ident);
	elf_type(elf_header->e_type, elf_header->e_ident);
	elf_entry(elf_header->e_entry, elf_header->e_ident);
	
	free(elf_header);
	fileClose_elf(file_open);
	return (0);
}
