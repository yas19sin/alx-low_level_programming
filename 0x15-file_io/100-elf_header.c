#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

/**
 * elf_header - Displays information from the ELF header of a file
 * @elf_filename: ELF file name
 */
void elf_header(const char *elf_filename) {
	if (elf_filename == NULL) {
		dprintf(2, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	int fd = open(elf_filename, O_RDONLY);
	if (fd == -1) {
		dprintf(2, "Error: Can't open file %s\n", elf_filename);
		exit(98);
	}

	Elf64_Ehdr elf_header;
	ssize_t bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));
	if (bytes_read == -1 || bytes_read != sizeof(Elf64_Ehdr)) {
		dprintf(2, "Error: Can't read from file %s\n", elf_filename);
		close(fd);
		exit(98);
	}

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; ++i)
		printf("%02x%c", elf_header.e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');

	printf("  Class:							 %s\n", elf_header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:							  %s\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:						   %d (current)\n", elf_header.e_ident[EI_VERSION]);
	printf("  OS/ABI:							%s\n", elf_header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Unknown");
	printf("  ABI Version:					   %d\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type:							  %s\n", elf_header.e_type == ET_EXEC ? "EXEC (Executable file)" : "Unknown");
	printf("  Entry point address:			   0x%lx\n", (unsigned long)elf_header.e_entry);

	close(fd);
}
