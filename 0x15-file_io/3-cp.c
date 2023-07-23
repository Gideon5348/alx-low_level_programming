#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>

#define BUF_SIZE 1024

void display_error_and_exit(const char *format, ...);

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUF_SIZE];

	if (argc != 3)
	{
		display_error_and_exit("Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		display_error_and_exit("Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_to == -1)
	{
		close(fd_from);
		display_error_and_exit("Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	while ((bytes_read = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			close(fd_from);
			close(fd_to);
			display_error_and_exit("Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		close(fd_from);
		close(fd_to);
		display_error_and_exit("Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		display_error_and_exit("Error: Can't close fd\n");
		exit(100);
	}

	return (0);
}

/**
 * display_error_and_exit - Displays an error message to stderr and exits.
 * @format: The format string for the error message.
 * @...: Variable arguments for the format string.
 */

void display_error_and_exit(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
}
