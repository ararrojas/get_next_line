#include <stdio.h>

int	main(int ac, char **av)
{
	int 	fd;
	char	*line;

	if (ac == 1)
		write(1, "File name missing.\n", 19);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			write(1, "Cannot read file.\n", 18);
		else
		{
			line = get_next_line(fd);
			while(line)
			{
				printf("-----------------\n");
				printf("%s", line);
				free(line);
				line = get_next_line(fd);
			}
			close(fd);
		}
	}
	return (0);
}
