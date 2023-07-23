#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

/* Function prototypes */
void display_usage_and_exit(const char *program_name);
void display_read_error_and_exit(const char *file_name);
void display_write_error_and_exit(const char *file_name);
void display_close_error_and_exit(int fd);

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, otherwise exits with an error code.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUF_SIZE];
	struct stat st;

	if (argc != 3)
	{
		display_usage_and_exit(argv[0]);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		display_read_error_and_exit(argv[1]);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
	{
		display_write_error_and_exit(argv[2]);
	}

	do {
		bytes_read = read(fd_from, buffer, BUF_SIZE);
		if (bytes_read == -1)
		{
			display_read_error_and_exit(argv[1]);
		}

		if (bytes_read > 0)
		{
			bytes_written = write(fd_to, buffer, bytes_read);
			if (bytes_written == -1 || bytes_written != bytes_read)
			{
				display_write_error_and_exit(argv[2]);
			}
		}
	} while (bytes_read > 0);

	if (fstat(fd_from, &st) == -1)
	{
		display_read_error_and_exit(argv[1]);
	}

	if (fchmod(fd_to, st.st_mode) == -1)
	{
		display_write_error_and_exit(argv[2]);
	}

	if (close(fd_from) == -1)
	{
		display_close_error_and_exit(fd_from);
	}

	if (close(fd_to) == -1)
	{
		display_close_error_and_exit(fd_to);
	}

	return (0);
}

/**
 * display_usage_and_exit - Displays usage message and exits with code 97.
 * @program_name: The name of the program.
 */

void display_usage_and_exit(const char *program_name)
{
	dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", program_name);
	exit(97);
}

/**
 * display_read_error_and_exit - Displays read error and exits with code 98.
 * @file_name: The name of the file that encountered the read error.
 */

void display_read_error_and_exit(const char *file_name)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_name);
	exit(98);
}

/**
 * display_write_error_and_exit - Displays write error and exits with code 99.
 * @file_name: The name of the file that encountered the write error.
 */

void display_write_error_and_exit(const char *file_name)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_name);
	exit(99);
}

/**
 * display_close_error_and_exit - Displays close error and exits with code 100.
 * @fd: The file descriptor that encountered the close error.
 */

void display_close_error_and_exit(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}
