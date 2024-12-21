/*#include "get_next_line.c"
#include "get_next_line.h"
#include "get_next_line_utils.c"*/

#include "get_next_line_bonus.c"
#include "get_next_line_bonus.h"
#include "get_next_line_utils_bonus.c"

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd1;
	int	fd2;
	char *line;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);

	/*while((line = get_next_line(fd1)))
	{
		printf ("%s", line);
		free(line);
	}*/
	for (int i = 0; i < 3; i++)
	{
		printf("%s", get_next_line(fd1));
	}
	while((line = get_next_line(fd2)))
	{
		printf ("%s", line);
		free(line);
	}
	close(fd2);
	while((line = get_next_line(fd1)))
    {
        printf ("%s", line);
        free(line);
    }
	close(fd1);
	return 0;
}
