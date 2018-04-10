/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:53:29 by nvergnac          #+#    #+#             */
/*   Updated: 2018/04/10 15:35:43 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_path_repartition(t_info *info)
{
	t_path	*path_tmp;
	int		sum;
	int		i;

	i = 0;
	sum = 0;
	path_tmp = BEST_SOL->first_path;
	if (!(info->path_repart = (int*)malloc(sizeof(int) * BEST_SOL->path_nb)))
		exit(0);
	while (i < BEST_SOL->path_nb)
	{
		info->path_repart[i] = BEST_SOL->cycles - path_tmp->path_len;
		sum += info->path_repart[i];
		i++;
		path_tmp = path_tmp->next;
	}
	i = 0;
	while (ANT_NB != sum)
	{
		i = i % BEST_SOL->path_nb;
		info->path_repart[i] += 1;
		sum += 1;
		i++;
	}
}

void	ft_init_ants_tab(t_info *info)
{
	int		i;

	i = 0;
	if (!(ANT_TAB = (t_ant *)malloc(sizeof(t_ant) * ANT_NB)))
		exit(0);
	while (i < ANT_NB)
	{
		ANT_TAB[i].ant = i + 1;
		ANT_TAB[i].path_index = 0;
		ANT_TAB[i].path_len = 0;
		ANT_TAB[i].index_room_act = 0;
		ANT_TAB[i].flag_print = 1;
		i++;
	}
}

int		ft_check_if_can_move(t_info *info, int i)
{
	int	k;

	k = 0;
	if (ft_get_next_index(info, ANT_TAB[i]) == INDEX_END)
		return (0);
	if (ANT_TAB[i].index_room_act == INDEX_END)
		return (1);
	while (k < i)
	{
		if (ft_get_next_index(info, ANT_TAB[i]) ==
				ANT_TAB[k].index_room_act)
			return (1);
		k++;
	}
	return (0);
}

void	ft_affect_ant_to_path(t_info *info)
{
	t_path	*path_tmp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	path_tmp = BEST_SOL->first_path;
	while (i < ANT_NB)
	{
		k = k % BEST_SOL->path_nb;
		if (info->path_repart[k] > 0)
		{
			if (k == 0)
				path_tmp = BEST_SOL->first_path;
			ANT_TAB[i].path_index = path_tmp->path_index;
			ANT_TAB[i].path_len = path_tmp->path_len;
			ANT_TAB[i].index_room_act = path_tmp->path_index[0];
			info->path_repart[k] = info->path_repart[k] - 1;
			i++;
		}
		path_tmp = path_tmp->next;
		k++;
	}
}

void	ft_move_ants(t_info *info)
{
	int	i;

	i = 0;
	ft_init_ants_tab(info);
	ft_path_repartition(info);
	ft_affect_ant_to_path(info);
	while (ft_all_ants_reached_end(info) == 1)
	{
		i = 0;
		info->print_count = 0;
		while (i < ANT_NB)
		{
			if (ft_check_if_can_move(info, i) == 0)
				ANT_TAB[i].index_room_act = ft_get_next_index(info, ANT_TAB[i]);
			ft_print_ant(info, i);
			i++;
		}
		ft_putstr("\n");
	}
}
