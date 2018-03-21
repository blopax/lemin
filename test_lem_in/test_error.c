/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:17:37 by atourner          #+#    #+#             */
/*   Updated: 2018/03/19 18:34:41 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void	error_gestion(FILE *fd, FILE *ftmp, char *str, char *av)
{
	ft_printf("\033[0;31m🀫\033[0;0m");
	fprintf(fd, "test %s\n wrong\n", av);
	fprintf(fd, "Needed answer : [Error]\nFound answer : [%s]\n", str);
//	free(str);
	if (!(str = ft_strnew(100)))
		return ;
	fgets(str, 100, ftmp);
	fprintf(fd, "Error is %s", str);
}

int		main(int ac, char **av)
{
	char	*str;
	char	*tmp;
	FILE	*fd;
	FILE	*ftmp;

	fd = fopen("error.txt", "a");
	ftmp = fopen(av[1], "r");
	get_next_line(0, &str);
	if (!ft_strcmp(str, "ERROR"))
		ft_printf("\033[0;32m🀫\033[0;0m");
	else
		error_gestion(fd, ftmp, str, av[1]);
	fclose(ftmp);
	fclose(fd);
	free(tmp);
	free(str);
	return (0);
}
