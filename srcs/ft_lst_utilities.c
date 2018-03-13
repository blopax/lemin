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
	int		flag;
	t_link	*linked_room_tmp;

	flag = 0;
	new = 0;
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

void	ft_add_room(char *line, t_info *info, int type)
{
	t_room	*new;
	int		flag;
	char	*tmp;
	t_room	*room_tmp;

	flag = 0;
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
}
