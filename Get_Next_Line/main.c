
#include "get_next_line.h"
# include <stdio.h>

int main()
{
	int		fd;
	char	*line;
	
	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (!line)
		{
			free (line);
			return (0);
		}
		free (line);
	}
	close(fd);
	return (0);
}