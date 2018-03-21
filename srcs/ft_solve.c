/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:54:33 by nvergnac          #+#    #+#             */
/*   Updated: 2018/03/21 20:56:27 by pclement         ###   ########.fr       */
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

int		ft_get_last_index(t_path *path)
{
	int i;

	i = 0;
	while (path->path_index[i] != 0)
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

int		ft_check_black_room(t_info *info, int *tab_index, int index)
{
	int	i;

	i = 0;
	while (i < ROOM_NB)
	{
		if (tab_index[i] == index)
			return (1);
		i++;
	}
	return (0);
}

void	ft_flag(t_info *info, t_path *last_path)
{
	if (ft_get_last_index(last_path) == INDEX_END)
		last_path->flag = 1;
}

void	ft_solve(t_info *info)
{
	t_path	*path_tmp;
	t_path	*path_last;
	t_room	*room;
	t_link	*link_tmp;
	int		index_room;
	int		path_index;

	if (!PATH)
		PATH = ft_path_init(info, 0, START->index);
	path_tmp = PATH;
	path_index = 0;
	while (path_tmp)
	{
		path_index++;
		path_last = ft_last(PATH);
		index_room = ft_get_last_index(path_tmp);
		room = ft_find_room(info, index_room);
		link_tmp = room->linked_room;
		while (link_tmp && path_tmp->flag != 1)
		{
			if (ft_check_black_room(info, path_tmp->path_index,
						ft_get_index(info, link_tmp->name)) == 0)
			{
				path_last->next = ft_path_init(info, path_tmp, ft_get_index(info, link_tmp->name));
				path_last = ft_last(PATH);
				ft_flag(info, path_last);
			}
				link_tmp = link_tmp->next;
		}
		path_tmp = path_tmp->next;
		if (path_index % 1000 == 0)
		{
			ft_show_path(info, PATH);
			ft_putstr("PATH INDEX = \t");
			ft_putnbr (path_index);
			ft_putstr("\n");
		}
	}

}
