/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:18:04 by nvergnac          #+#    #+#             */
/*   Updated: 2018/03/19 23:23:17 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*t_path	*ft_path_init(t_sol sol_lst)
{
	t_room *path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		exit(0);
	path->path_room = sol_lst;
	path->next = NULL;
	return (path);
}
*/
t_room	*ft_room_init(int x, int y, int type, int index)
{
	t_room *room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		exit(0);
	room->x = x;
	room->y = y;
	room->index = index;
	room->type = type;
	room->name = 0;
	room->link_room_count = 0;
	room->linked_room = 0;
	room->next = NULL;
	return (room);
}

t_link	*ft_linked_room_init(char *room_name)
{
	t_link	*new_linked_room;

	if (!(new_linked_room = (t_link*)malloc(sizeof(t_link))))
		exit(0);
	new_linked_room->name = ft_strdup(room_name);
	new_linked_room->next = NULL;
	return (new_linked_room);
}

t_info	*ft_info_init(void)
{
	t_info	*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		exit(0);
	FIRST = ft_room_init(-1, -1, 0, 0);
	START = 0;
	END = 0;
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
	INDEX = 0;
	SIZE = 0;
	return (info);
}
