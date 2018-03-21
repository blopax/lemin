/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:28:30 by atourner          #+#    #+#             */
/*   Updated: 2018/03/19 16:10:03 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lem.h"
#include <stdio.h>

int		check_double(int ant_this_turn[1000], int i)
{
	int		j;

	j = -1;
	while (++j < i)
		if (ant_this_turn[i] == ant_this_turn[j])
			return (1);
	return (0);
}

void	error_gestion(char *map_name)
{
	FILE	*fd;

	fd = fopen("validity.txt", "a");
	fprintf(fd, "Problem in map %s\n\n", map_name);
}
