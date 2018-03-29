/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_utilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:36:03 by nvergnac          #+#    #+#             */
/*   Updated: 2018/03/29 17:57:52 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_get_index(t_info *info, char *name)
{
	t_room	*tmp_room;

	tmp_room = FIRST;
	while (ft_strcmp(tmp_room->name, name) != 0)
		tmp_room = tmp_room->next;
	return (tmp_room->index);
}

t_room	*ft_find_room(t_info *info, int index_room)
{
	t_room	*tmp_room;

	tmp_room = FIRST;
	while (tmp_room && tmp_room->index != index_room)
		tmp_room = tmp_room->next;
	return (tmp_room);
}

int		ft_get_last_index(t_info *info, t_path *path)
{
	int i;

	i = 0;
	while (i < ROOM_NB && path->path_index[i] != 0)
		i++;
	return (path->path_index[i - 1]);
}

t_path	*ft_last(t_path *path)
{
	t_path *path_last;

	path_last = path;
	while (path_last->next)
		path_last = path_last->next;
	return (path_last);
}

void	ft_flag(t_info *info, t_path *last_path)
{
	if (ft_get_last_index(info, last_path) == INDEX_END)
		last_path->flag = 0;
}

void	ft_clean_room_type(t_info *info)
{
	t_room *tmp_room;
	
	tmp_room = FIRST;
	while (tmp_room)
	{
		if (tmp_room->type == 3)
			tmp_room->type = 0;
		tmp_room = tmp_room->next;
	}
}
