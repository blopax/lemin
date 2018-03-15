#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*str;
	char	*tmp;
	FILE	*fd;
	FILE	*ftmp;

	if (!(tmp = malloc(sizeof(char) * 100)))
	{
		printf("Error in malloc, please retry\n");
		return (0);
	}
	fd = fopen("error.txt", "a");
	get_next_line(0, &str);
	if (!ft_strcmp(str, "ERROR"))
		printf("\033[0;32m🀫\033[0;0m");
	else
	{
		ftmp = fopen(av[1], "r");
		printf("\033[0;31m🀫\033[0;0m");
		fgets(tmp, 100, ftmp);
		fprintf(fd, "test %s\n wrong\nNeeded answer : [Error]\nFound answer : [%s]\n Error is %s", av[1], str, tmp);
		fclose(ftmp);
	}
	fclose(fd);
	free(tmp);
	free(str);
	return (0);
}
