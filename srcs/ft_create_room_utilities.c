/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_room_utilities.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:22:22 by nvergnac          #+#    #+#             */
/*   Updated: 2018/04/10 15:21:46 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_create_first_room(char *line, char *tmp, t_info *info, int type)
{
	FIRST->x = X_ROOM;
	FIRST->y = Y_ROOM;
	FIRST->type = type;
	FIRST->index = INDEX;
	FIRST->name = ft_strdup(ft_strncpy(tmp, line, SIZE));
	if (type == 1)
		START = FIRST;
	else if (type == 2)
		END = FIRST;
}

void	ft_create_room(char *line, char *tmp, t_info *info, int type)
{
	t_room	*new;
	t_room	*room_tmp;

	room_tmp = FIRST;
	new = ft_room_init(X_ROOM, Y_ROOM, type, INDEX);
	new->name = ft_strdup(ft_strncpy(tmp, line, SIZE));
	while (room_tmp->next)
		room_tmp = room_tmp->next;
	room_tmp->next = new;
	if (type == 1)
		START = room_tmp->next;
	else if (type == 2)
		END = room_tmp->next;
}
