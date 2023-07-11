#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define BUFFER_SIZE 1024

/**
 * print_error - Prints the error message to standard error.
 * @message: The error message to print.
 */
void print_error(const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
}

/**
 * print_elf_header - Prints the information from the ELF header.
 * @header: Pointer to the ELF header.
 */
void print_elf_header(const Elf64_Ehdr *header)
{
    int i;

    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header->e_ident[i]);
    printf("\n");

    printf("  Class:                             ");
    if (header->e_ident[EI_CLASS] == ELFCLASS32)
        printf("ELF32\n");
    else if (header->e_ident[EI_CLASS] == ELFCLASS64)
        printf("ELF64\n");
    else
        printf("<unknown>\n");

    printf("  Data:                              ");
    if (header->e_ident[EI_DATA] == ELFDATA2LSB)
        printf("2's complement, little endian\n");
    else if (header->e_ident[EI_DATA] == ELFDATA2MSB)
        printf("2's complement, big endian\n");
    else
        printf("<unknown>\n");

    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
        case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
        case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
        case ELFOSABI_ARM: printf("ARM\n"); break;
        case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
        default: printf("<unknown>\n"); break;
    }

    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (header->e_type)
    {
        case ET_NONE: printf("NONE (No file type)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown>\n"); break;
    }

    printf("  Entry point address:               0x%lx\n", header->e_entry);
}

/**
 * main - Displays the information contained in the ELF header of an ELF file.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: 0 on success, or the exit code on failure.
 */
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error("Error: Could not open file");
		exit(98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		print_error("Error: Failed to read ELF header");
		close(fd);
		exit(98);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
		header.e_ident[EI_MAG1] != ELFMAG1 ||
		header.e_ident[EI_MAG2] != ELFMAG2 ||
		header.e_ident[EI_MAG3] != ELFMAG3)
	{
		print_error("Error: Not an ELF file");
		close(fd);
		exit(98);
	}

	print_elf_header(&header);

	if (close(fd) == -1)
	{
		print_error("Error: Could not close file");
		exit(98);
	}

	return (0);
}
