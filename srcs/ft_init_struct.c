/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:18:04 by nvergnac          #+#    #+#             */
/*   Updated: 2018/03/12 21:15:34 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_room	*ft_room_init(void)
{
	t_room *room;
	t_link *link;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		exit(0);
	if (!(link = (t_link*)malloc(sizeof(t_link))))
		exit(0);
	link->name = 0;
	link->next = NULL;
	room->linked_room = link;
	room->next = NULL;
	room->name = 0;
	room->x = -1;
	room->y = -1;
	return (room);
}

t_info	*ft_info_init(void)
{
	t_info	*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		exit(0);
	FIRST = ft_room_init();
	CMD = 0;
	TREAT_OVER = 0;
	ANT_NB = 0;
	ROOM_NB = 0;
	PHASE = 1;
	MAX_PATH = 0;
	X_ROOM = -1;
	Y_ROOM = -1;
	SIZE = 0;
	return (info);
}
