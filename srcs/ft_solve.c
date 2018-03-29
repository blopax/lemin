/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:54:33 by nvergnac          #+#    #+#             */
/*   Updated: 2018/03/29 18:08:51 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int  ft_check_black_room(t_info *info, int *tab_index, int index)
{
	int i;

	i = 0;
	while (i < ROOM_NB)
	{
		if (tab_index[i] == index)
			return (1);
		i++;
	}
	return (0);
}

void	ft_set_black_room(t_info *info, int index, t_path *path_last)
{
	t_room	*room_tmp;

	room_tmp = ft_find_room(info, index);
	if (room_tmp->type == 3)
		path_last->flag += 1;
	if (room_tmp->type == 0)
		room_tmp->type = 3;
}

void	ft_build_path(t_info *info, t_path *path_tmp, t_link *link_tmp)
{
	while (link_tmp && path_tmp->flag == FLAG)
	{
		if (ft_check_black_room(info, path_tmp->path_index,
					ft_get_index(info, link_tmp->name)) == 0)
		{
			ft_last(PATH)->next = ft_path_init(info, path_tmp, ft_get_index(info, link_tmp->name));
			ft_set_black_room(info, ft_get_index(info, link_tmp->name), ft_last(PATH));
			ft_flag(info, ft_last(PATH));
		}
		link_tmp = link_tmp->next;
	}
}

int		ft_check_end(t_info *info)
{
	t_path *path_tmp;

	path_tmp = PATH;
	while (path_tmp)
	{
		if (path_tmp->flag == 0 || path_tmp->flag == -1)
			return (1);
		path_tmp = path_tmp->next;
	}
	return (0);
}

int		ft_solve(t_info *info)
{
	t_path	*path_tmp;
	t_room	*room;
	t_link	*link_tmp;

	if (!PATH)
		PATH = ft_path_init(info, 0, START->index);
	path_tmp = PATH;
	while (path_tmp)
	{
		INDEX_ROOM = ft_get_last_index(info, path_tmp);
		room = ft_find_room(info, INDEX_ROOM);
		link_tmp = room->linked_room;
		ft_build_path(info, path_tmp, link_tmp);
		path_tmp = path_tmp->next;
	}
	if (ft_check_end(info) == 0)
	{
		ft_error();
		return (0);
	}
	ft_sol_list(info);
	ft_count_exclusive_path(info->sol_first, info);
	RECURSIVE++;
	FLAG++;
	ft_show_path(info, PATH);
	ft_clean_room_type(info);
	if (RECURSIVE < 3 && MAX_PATH > EX_SOL)
		ft_solve(info);
	ft_show_best_sol(info);
	return (0);
}
