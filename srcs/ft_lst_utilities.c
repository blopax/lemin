/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:42:39 by pclement          #+#    #+#             */
/*   Updated: 2018/03/12 18:48:00 by pclement         ###   ########.fr       */
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

