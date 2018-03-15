/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:18:04 by nvergnac          #+#    #+#             */
/*   Updated: 2018/03/15 14:31:00 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_room	*ft_room_init(void)
{
	t_room *room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		exit(0);
	room->x = -1;
	room->y = -1;
	room->type = 0;
	room->name = 0;
	room->linked_room = 0;
	room->next = NULL;
	return (room);
}

t_info	*ft_info_init(void)
{
	t_info	*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		exit(0);
	FIRST = ft_room_init();
	START = 0;
	START_COUNT = 0;
	END_COUNT = 0;
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
