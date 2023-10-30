#include "main.h"

/**
 * file_check_elf - Check if the provided bytes represent a valid ELF file
 * @e_ident: Array of bytes containing the ELF magic bytes.
 */
void file_check_elf(unsigned char *e_ident)
{
	int itr;

	for (itr = 0; itr < 4; itr++)
	{
		if (e_ident[itr] != 127 &&
		    e_ident[itr] != 'E' &&
		    e_ident[itr] != 'L' &&
		    e_ident[itr] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * elf_magic - the magic bytes in the ELF header
 * @e_ident: Array of bytes containing the ELF magic bytes
 */
void elf_magic(unsigned char *e_ident)
{
	int itr;

	printf("  Magic:   ");

	for (itr = 0; itr < EI_NIDENT; itr++)
	{
		printf("%02x", e_ident[itr]);

		if (itr == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * elf_class - the ELF class information from the ELF header.
 * @e_ident: Array of bytes containing ELF header information.
 */
void elf_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * elf_data - Print the ELF data format information from the ELF header
 * @e_ident: Array of bytes containing ELF header information
 */
void elf_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * elf_version - Print the ELF version information from the ELF header
 * @e_ident: Array of bytes containing ELF header information
 */
void elf_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
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
 * elf_osabi - Print the OS/ABI information from the ELF header
 * @e_ident: Array of bytes containing ELF header information
 */
void elf_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
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
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * elf_abi - Print the ABI Version information from the ELF header
 * @e_ident: Array of bytes containing ELF header information
 */
void elf_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * elf_type - Print the ELF type information from the ELF header
 * @e_type:   ELF type from the ELF header.
 * @e_ident:  Array of bytes containing ELF header information
 */
void elf_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
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
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * elf_entry - Print the Entry point address from the ELF header
 * @e_entry: Entry point address from the ELF header
 * @e_ident: Array of bytes containing ELF header information
 */
void elf_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Close the file descriptor representing an ELF file
 * @elf: File descriptor to close
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Function for reading and processing an ELF file header
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments, including the ELF file name
 * Return: 0 to indicate successful program execution
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int file_D, file_r;

	file_D = open(argv[1], O_RDONLY);
	if (file_D == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(file_D);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	file_r = read(file_D, header, sizeof(Elf64_Ehdr));
	if (file_r == -1)
	{
		free(header);
		close_elf(file_D);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	file_check_elf(header->e_ident);
	printf("ELF Header:\n");
	elf_magic(header->e_ident);
	elf_class(header->e_ident);
	elf_data(header->e_ident);
	elf_version(header->e_ident);
	elf_osabi(header->e_ident);
	elf_abi(header->e_ident);
	elf_type(header->e_type, header->e_ident);
	elf_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(file_D);
	return (0);
}
