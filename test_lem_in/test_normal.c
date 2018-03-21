/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:17:33 by atourner          #+#    #+#             */
/*   Updated: 2018/03/16 10:25:58 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void	normal_gestion(FILE *fd, char *str, char *av, FILE *ftmp)
{
	int		i;
	int		best;
	int		shortest;

	i = 1;
	while (get_next_line(0, &str) && i++)
		free(str);
	if (!(str = ft_strnew(50)))
		return ;
	fgets(str, 50, ftmp);
	best = atoi(&str[1]);
	fgets(str, 50, ftmp);
	shortest = atoi(&str[1]);
	if (i == best)
		ft_printf("\033[0;32m🀫\033[0;0m");
	else
	{
		ft_printf("\033[0;33m🀫\033[0;0m");
		fprintf(fd, "Test %s\n not optimal\n", av);
		fprintf(fd, "Needed move optimum : [%d]\n", best);
		fprintf(fd, "Needed move only took shortest path : [%d]\n", shortest);
		fprintf(fd, "You did it in [%d] moves\n\n", i);
	}
}

void	error_gestion(FILE *fd, char *str, char *av)
{
	free(str);
	ft_printf("\033[0;31m🀫\033[0;0m");
	fprintf(fd, "Test %s returned Error\n", av);
}

int		main(int ac, char **av)
{
	char	*str;
	FILE	*fd;
	FILE	*ftmp;
	int		i;

	fd = fopen("normal.txt", "a");
	get_next_line(0, &str);
	ftmp = fopen(av[1], "r");
	i = 0;
	if (!ft_strcmp(str, "ERROR"))
		error_gestion(fd, str, av[1]);
	else
	{
		free(str);
		normal_gestion(fd, str, av[1], ftmp);
	}
	fclose(fd);
	fclose(ftmp);
	return (0);
}
