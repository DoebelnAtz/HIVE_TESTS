#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int get_next_line(const int fd, char **line);

int		main(int argc, char **argv)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		fd5;
	int		fd6;
	int		fdout;
	int		output;

	fdout = open("output", O_RDWR | O_CREAT, 0666 | O_APPEND);
	output = fdout;
	if (argc > 1 && *argv[1] == 'a')
	{
		fd1 = open("testfile1", O_RDONLY);
		while (get_next_line(fd1, &line) > 0)
		{
			ft_putendl_fd(line, output);
			free(line);
		}
		close(fd1);
	}
	if (argc > 2 && *argv[2] == 'b')
	{
		fd2 = open("testfile2", O_RDONLY);
		fd3 = open("testfile3", O_RDONLY);
		fd4 = open("testfile4", O_RDONLY);
		get_next_line(fd2, &line);
		ft_putendl_fd(line, output);
		free(line);
		get_next_line(fd3, &line);
		ft_putendl_fd(line, output);
		free(line);
		get_next_line(fd4, &line);
		ft_putendl_fd(line, output);
		free(line);
		get_next_line(fd3, &line);
		ft_putendl_fd(line, output);
		free(line);
		close(fd2);
		close(fd3);
		close(fd4);
	}
	if (argc > 3 && *argv[3] == 'c')
	{
		fd5 = open("testfile5", O_RDONLY);
		fd6 = open("testfile6", O_RDONLY);
		while (get_next_line(fd5, &line) > 0)
		{
			ft_putendl_fd(line, output);
			free(line);
		}
		if (get_next_line(fd6, &line))
		{
			ft_putendl_fd(line, output);
			free(line);
		}
		close(fd6);
		fd6 = open("testfile7", O_RDONLY);
		if (get_next_line(fd6, &line))
		{
			printf("\033[1;31m");
			printf("ERROR\n");
			printf("\033[0m;");
			ft_putendl_fd(line, output);
			free(line);
		}
		close(fd6);
		close(fd5);
	}
	if (argc > 4 && *argv[4] == 'd')
	{
		fd6 = open("testfile8", O_RDONLY);
		while (get_next_line(fd6, &line) > 0)
		{
			ft_putendl_fd(line, output);
			free(line);
		}
		close(fd6);
	}
	if (argc > 5 && *argv[5] == 'e')
	{
		fd1 = open("testfile9", O_RDONLY);
		fd2 = open("testfile10", O_RDONLY);
		while (get_next_line(fd1, &line) > 0)
		{
			ft_putendl_fd(line, output);
			free(line);
		}
		get_next_line(fd2, &line);
		ft_putendl_fd(line, output);
		free(line);
		close(fd1);
		close(fd2);
	}
	close(fdout);
	if (argc == 7 && *argv[6] == 'y')
	{
		while (1)
		{

		}
	}
}
