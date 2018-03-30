/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ants_utilities.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:53:47 by nvergnac          #+#    #+#             */
/*   Updated: 2018/03/30 19:55:55 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_get_next_index(t_ant ant)
{
	int	i;

	i = 0;
	while (ant.path_index[i] != ant.index_room_act)
		i++;
	return (ant.path_index[i + 1]);
}

void	ft_print_ant(t_info *info, int i)
{
	if (ANT_TAB[i].index_room_act != ANT_TAB[i].path_index[0] &&
			ANT_TAB[i].flag_print == 1)
	{
		if (info->print_count == 1)
			ft_putstr(" ");
		ft_putstr("L");
		ft_putnbr((int)ANT_TAB[i].ant);
		ft_putstr("-");
		ft_putstr(ft_find_room(info, ANT_TAB[i].index_room_act)->name);
		if (ANT_TAB[i].index_room_act == INDEX_END)
			ANT_TAB[i].flag_print = 0;
		info->print_count = 1;
	}
}

int		ft_all_ants_reached_end(t_info *info)
{
	int i;

	i = 0;
	while (i < ANT_NB)
	{
		if (ANT_TAB[i].index_room_act != INDEX_END)
			return (1);
		i++;
	}
	return (0);
}
