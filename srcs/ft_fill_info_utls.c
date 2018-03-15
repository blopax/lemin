/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_info_utls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:42:39 by pclement          #+#    #+#             */
/*   Updated: 2018/03/15 17:27:29 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_check_room_coord(t_info *info)
{
	t_room	*room_tmp;

	room_tmp = FIRST;
	while (room_tmp)
	{
		if (X_ROOM == room_tmp->x && Y_ROOM == room_tmp->y)
			return (1);
		room_tmp = room_tmp->next;
	}
	return (0);
}

int		ft_check_room_name(char *line, t_info *info)
{
	char	*tmp;
	t_room	*room_tmp;

	if (!(tmp = ft_strnew(SIZE)))
		exit(0);
	room_tmp = FIRST;
	while (room_tmp)
	{
		if (ft_strcmp(room_tmp->name, ft_strncpy(tmp, line, SIZE)) == 0)
		{
			ft_safe_free(tmp);
			return (1);
		}
		room_tmp = room_tmp->next;
	}
	ft_safe_free(tmp);
	return (ft_check_room_coord(info));
}

int		ft_check_p2(char *line, t_info *info)
{
	int blank;

	blank = 0;
	SIZE = ft_strlen(line) - 1;
	if (!line || ft_isdigit(line[SIZE]) == 0 || SIZE < 4)
		return (1);
	while (blank < 2 && line[SIZE])
	{
		if (line[SIZE] != ' ' && ft_isdigit(line[SIZE]) == 0)
			return (1);
		if (line[SIZE] == ' ')
		{
			blank++;
			if (blank == 1)
				Y_ROOM = ft_atoi(line + SIZE);
			if (blank == 2)
				X_ROOM = ft_atoi(line + SIZE);
		}
		if (blank < 2)
			SIZE--;
	}
	if (X_ROOM == -1 || Y_ROOM == -1)
		return (1);
	return (ft_check_room_name(line, info));
}


