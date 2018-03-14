/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:42:39 by pclement          #+#    #+#             */
/*   Updated: 2018/03/13 18:20:25 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_link	*ft_init_linked_room(char *room_name)
{
	t_link	*new_linked_room;

	if (!(new_linked_room = (t_link*)malloc(sizeof(t_link))))
		exit(0);
	new_linked_room->name = ft_strdup(room_name);
	new_linked_room->next = NULL;
	return (new_linked_room);
}

void	ft_add_linked_room(t_link *linked_room, char *room_name)
{
	t_link	*new;
	t_link	*linked_room_tmp;

	if (!(new = (t_link*)malloc(sizeof(t_link))))
		exit (0);
	linked_room_tmp = linked_room;
	while (linked_room_tmp)
	{
		if (ft_strcmp(linked_room_tmp->name, room_name) == 0)
			break ;
		linked_room = linked_room_tmp->next;
	}
	if (!linked_room_tmp)
	{
		linked_room_tmp = linked_room;
		new = ft_init_linked_room(room_name);
		if (linked_room == 0)
			linked_room = new;
		else
		{
			while (linked_room->next != 0)
				linked_room = linked_room->next;
			linked_room->next = new;
		}
	}
}

void	ft_browse_rooms(t_info *info, char *room1, char *room2)
{
	t_room		*room_tmp;
	room_tmp = FIRST;
	while (room_tmp)
	{
		if (ft_strcmp(room_tmp->name, room1) == 0)
			ft_add_linked_room(room_tmp->linked_room, room2);
		if (ft_strcmp(room_tmp->name, room2) == 0)
			ft_add_linked_room(room_tmp->linked_room, room1);
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

void	ft_add_room(char *line, t_info *info, int type)
{
	t_room	*new;
	char	*tmp;
	t_room	*room_tmp;

	new = 0;
	if (!(tmp=(char*)malloc(sizeof(char) * (SIZE + 1))))
		exit(0);
	room_tmp = FIRST;
	if (FIRST->x == -1)
	{
		room_tmp->x = X_ROOM;
		room_tmp->y = Y_ROOM;
		room_tmp->type = type;
		room_tmp->name = ft_strdup(ft_strncat(tmp, line, SIZE));
	}
	else
	{
		new = ft_room_init();
		new->x = X_ROOM;
		new->y = Y_ROOM;
		new->type = type;
		new->name = ft_strdup(ft_strncat(tmp, line, SIZE));
		while (room_tmp->next)
			room_tmp = room_tmp->next;
		room_tmp->next = new;
	}
	ft_safe_free(tmp);
}
