#include "main.h"
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

void check_elf_id(unsigned char *e_ident);
void display_magic_class(unsigned char *e_ident);
void display_elf_class(unsigned char *e_ident);
void display_data_class(unsigned char *e_ident);
void display_version_class(unsigned char *e_ident);
void display_abi_class(unsigned char *e_ident);
void display_osabi_class(unsigned char *e_ident);
void display_type_class(unsigned int e_type, unsigned char *e_ident);
void display_entry_class(unsigned long int e_entry, unsigned char *e_ident);
void close_elf_id(int elf);

/**
 * check_elf_id - Determine if a file adheres to the ELF format.
 * @e_ident: A pointer to an array storing ELF's magic numbers.
 * Description: This function scrutinizes the provided `e_ident`
 * array to ascertain whether the file adheres to the ELF standard.
 */
void check_elf_id(unsigned char *e_ident)
{
	int id;

	for (id = 0; id < 4; id++)
	{
		if (e_ident[id] != 127 &&
			e_ident[id] != 'E' &&
			e_ident[id] != 'L' &&
			e_ident[id] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * display_magic_class - Render the ELF header's magic numbers.
 * @e_ident: A pointer to an array that stores the ELF magic numbers.
 * Description: The magic numbers are presented with spaces between them.
 */
void display_magic_class(unsigned char *e_ident)
{
	int id;

	printf("  Magic:   ");

	for (id = 0; id < EI_NIDENT; id++)
	{
		printf("%02x", e_ident[id]);

		if (id == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * display_elf_class - Output the ELF header's class information.
 * @e_ident: A pointer to an array holding the ELF class data.
 */
void display_elf_class(unsigned char *e_ident)
{
	printf("  Class:							 ");

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
 * display_data_class - Output the data class of an ELF header.
 * @e_ident: A pointer to an array holding the ELF data class information.
 */
void display_data_class(unsigned char *e_ident)
{
	printf("  Data:							  ");

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
 * display_version_class - Output the version information of an ELF header.
 * @e_ident: A pointer to an array holding the ELF version data.
 */
void display_version_class(unsigned char *e_ident)
{
	printf("  Version:						   %d",
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
 * display_osabi_class - Output the OS/ABI information of an ELF header.
 * @e_ident: A pointer to an array holding the ELF OS/ABI data.
 */
void display_osabi_class(unsigned char *e_ident)
{
	printf("  OS/ABI:							");

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
 * display_abi_class - Output the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version data.
 */
void display_abi_class(unsigned char *e_ident)
{
	printf("  ABI Version:					   %d\n",
		   e_ident[EI_ABIVERSION]);
}

/**
 * display_type_class - Output the type information of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array holding the ELF class information.
 */
void display_type_class(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:							  ");

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
 * display_entry_class - Output the entry point address of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array holding the ELF class information.
 */
void display_entry_class(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:			   ");

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
 * close_elf_id - Close an ELF file.
 * @elf: The file descriptor of the ELF file to be closed.
 * Description: the file fails, the function exits with error code 98.
 */
void close_elf_id(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Display information from the ELF header of an ELF file.
 * @argc: The number of program arguments.
 * @argv: An array of pointers to the arguments.
 * Return: Returns 0 on successful execution.
 * Description: If the file is not a valid ELF file or the
 * function encounters an error, it exits with an error code of 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fd, read_status;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf_id(fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	read_status = read(fd, header, sizeof(Elf64_Ehdr));
	if (read_status == -1)
	{
		free(header);
		close_elf_id(fd);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf_id(header->e_ident);
	printf("ELF Header:\n");
	display_magic_class(header->e_ident);
	display_elf_class(header->e_ident);
	display_data_class(header->e_ident);
	display_version_class(header->e_ident);
	display_osabi_class(header->e_ident);
	display_abi_class(header->e_ident);
	display_type_class(header->e_type, header->e_ident);
	display_entry_class(header->e_entry, header->e_ident);

	free(header);
	close_elf_id(fd);
	return (0);
}
