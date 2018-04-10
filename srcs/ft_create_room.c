/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:22:05 by nvergnac          #+#    #+#             */
/*   Updated: 2018/04/10 17:52:38 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_add_room(char *line, t_info *info, int type)
{
	char	*tmp;

	INDEX++;
	if (!(tmp = ft_strnew(SIZE)))
		exit(0);
	if (FIRST->x == -1)
		ft_create_first_room(line, tmp, info, type);
	else
		ft_create_room(line, tmp, info, type);
	ROOM_NB++;
	ft_safe_free(tmp);
}

int		ft_add_linked_room(t_room *room, char *room_name)
{
	t_link	*new;
	t_link	*linked_room_tmp;

	new = ft_linked_room_init(room_name);
	linked_room_tmp = room->linked_room;
	if (!room->linked_room)
		room->linked_room = new;
	else
	{
		while (linked_room_tmp->next)
		{
			if (ft_strcmp(linked_room_tmp->name, room_name) == 0)
				return (ft_free_lst_link(new));
			linked_room_tmp = linked_room_tmp->next;
		}
		if (ft_strcmp(linked_room_tmp->name, room_name) == 0)
			return (ft_free_lst_link(new));
		linked_room_tmp->next = new;
	}
	room->link_room_count++;
	return (0);
}

void	ft_browse_rooms(t_info *info, char *room1, char *room2)
{
	t_room		*room_tmp;

	room_tmp = FIRST;
	while (room_tmp)
	{
		if (ft_strcmp(room_tmp->name, room1) == 0)
			ft_add_linked_room(room_tmp, room2);
		if (ft_strcmp(room_tmp->name, room2) == 0)
			ft_add_linked_room(room_tmp, room1);
		room_tmp = room_tmp->next;
	}
}

int		ft_link_rooms(t_info *info, char *room1, char *room2)
{
	t_room		*room_tmp;
	int			room1_check;
	int			room2_check;

	room_tmp = FIRST;
	room1_check = 0;
	room2_check = 0;
	while (room_tmp)
	{
		if (ft_strcmp(room_tmp->name, room1) == 0)
			room1_check++;
		if (ft_strcmp(room_tmp->name, room2) == 0)
			room2_check++;
		room_tmp = room_tmp->next;
	}
	if (room1_check != 1 || room2_check != 1)
		return (1);
	ft_browse_rooms(info, room1, room2);
	return (0);
}
