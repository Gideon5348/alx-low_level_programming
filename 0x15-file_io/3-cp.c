#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUF_SIZE 1024

int open_source_file(const char *filename);
int open_target_file(const char *filename);
void close_files(int fd_from, int fd_to);
int copy_file(int fd_from, int fd_to);

/**
 * main - Copies the content of a file to another file.
 * @ac: The number of arguments.
 * @av: An array of arguments.
 *
 * Return: 0 on success, or the corresponding error code on failure.
 */

int main(int ac, char **av)
{
	int fd_from, fd_to;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", av[0]);
		return (EXIT_FAILURE);
	}

	fd_from = open_source_file(av[1]);
	if (fd_from == -1)
		return (EXIT_FAILURE);

	fd_to = open_target_file(av[2]);
	if (fd_to == -1)
	{
		close(fd_from);
		return (EXIT_FAILURE);
	}

	if (copy_file(fd_from, fd_to) == -1)
	{
		close_files(fd_from, fd_to);
		return (EXIT_FAILURE);
	}

	close_files(fd_from, fd_to);
	return (EXIT_SUCCESS);
}

/**
 * open_source_file - Open the source file in read-only mode.
 * @filename: The name of the source file.
 *
 * Return: File descriptor of the opened source file, or -1 on failure.
 */

int open_source_file(const char *filename)
{
	int fd_from = open(filename, O_RDONLY);

	if (fd_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	return (fd_from);
}

/**
 * open_target_file - Open the target file in write-only mode.
 * @filename: The name of the target file.
 *
 * Return: File descriptor of the opened target file, or -1 on failure.
 */

int open_target_file(const char *filename)
{
	int fd_to = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	return (fd_to);
}

/**
 * close_files - Close both file descriptors.
 * @fd_from: File descriptor of the source file.
 * @fd_to: File descriptor of the target file.
 */

void close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
	if (close(fd_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
}

/**
 * copy_file - Copy data from the source file to the target file.
 * @fd_from: File descriptor of the source file.
 * @fd_to: File descriptor of the target file.
 *
 * Return: 0 on success, or -1 on failure.
 */

int copy_file(int fd_from, int fd_to)
{
	ssize_t read_status, write_status;
	char buf[BUF_SIZE];

	while ((read_status = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		write_status = write(fd_to, buf, read_status);
		if (write_status == -1 || write_status != read_status)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file\n");
			return (-1);
		}
	}

	if (read_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file\n");
		return (-1);
	}

	return (0);
}
