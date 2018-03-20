/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:54:33 by nvergnac          #+#    #+#             */
/*   Updated: 2018/03/20 20:56:37 by nvergnac         ###   ########.fr       */
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
	while (tmp_room->index != index_room)
		tmp_room = tmp_room->next;
	return (tmp_room);
}

int		ft_get_last_index(t_path *path)
{
	int i;

	i = 0;
	while (path->path_index[i] != 0)
		i++;
	return (path->path_index[i]);
}

t_path	*ft_last(t_path *path)
{
	t_path *path_last;

	path_last = path;
	while (path_last)
		path_last = path_last->next;
	return (path_last);
}

void	ft_solve(t_info *info)
{
	t_path	*path_tmp;
	t_path	*path_last;
	t_room	*room;
	int		index_room;

	if (!PATH)
		PATH = ft_path_init(info, 0, START->index);
	path_tmp = PATH;
	while (path_tmp)
	{
		path_last = ft_last(PATH);
		index_room = ft_get_last_index(path_tmp);
		room = ft_find_room(info, index_room);
		while (room->linked_room)
		{
			path_last->next = ft_path_init(info, path_tmp, ft_get_index(info, room->linked_room->name));
			path_last = ft_last(PATH);
			room->linked_room = room->linked_room->next;
		}
		path_tmp->flag = -1;
		path_tmp = path_tmp->next;
	}

}
