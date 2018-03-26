/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:42:39 by pclement          #+#    #+#             */
/*   Updated: 2018/03/26 19:52:22 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_add_room(char *line, t_info *info, int type)
{
	t_room	*new;
	char	*tmp;
	t_room	*room_tmp;

	INDEX++;
	new = 0;
	if (!(tmp = ft_strnew(SIZE)))
		exit(0);
	room_tmp = FIRST;
	if (FIRST->x == -1)
	{
		room_tmp->x = X_ROOM;
		room_tmp->y = Y_ROOM;
		room_tmp->type = type;
		room_tmp->index = INDEX;
		room_tmp->name = ft_strdup(ft_strncpy(tmp, line, SIZE));
		if (type == 1)
			START = FIRST;
		else if (type == 2)
			END = FIRST;
	}
	else
	{
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
				return (1);
			linked_room_tmp = linked_room_tmp->next;
		}
		if (ft_strcmp(linked_room_tmp->name, room_name) == 0)
			return (1);
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

void	ft_show_linked_rooms(t_room *lst)
{
	t_link	*linked_room;

	linked_room = lst->linked_room;
	if (!linked_room)
		ft_putstr("No linked room");
	while (linked_room)
	{
		ft_putstr("\t");
		ft_putstr(linked_room->name);
		ft_putstr("\n");
		linked_room = linked_room->next;
	}
}

void	ft_show_lst_room(t_room *room_lst)
{
	t_room *tmp;

	tmp = room_lst;
	while (tmp)
	{
		ft_putstr("NAME : ");
		ft_putstr(tmp->name);
		ft_putstr("\n");
		ft_putstr("X : ");
		ft_putnbr(tmp->x);
		ft_putstr("\n");
		ft_putstr("Y : ");
		ft_putnbr(tmp->y);
		ft_putstr("\n");
		ft_putstr("TYPE : ");
		ft_putnbr(tmp->type);
		ft_putstr("\n");
		ft_putstr("INDEX : ");
		ft_putnbr(tmp->index);
		ft_putstr("\n");
		ft_putstr("NB of linked rooms: ");
		ft_putnbr(tmp->link_room_count);
		ft_putstr("\n");
		ft_show_linked_rooms(tmp);
		ft_putstr("\n");
		ft_putstr("\n");
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

void	ft_show_info(t_info *info)
{
	ft_putstr("TREAT_OVER : ");
	ft_putnbr(info->treatment_over);
	ft_putstr("\n");
	ft_putstr("PHASE : ");
	ft_putnbr(info->phase);
	ft_putstr("\n");
	ft_putstr("ANT_NB : ");
	ft_putnbr(info->ant_nb);
	ft_putstr("\n");
	ft_putstr("room_nb : ");
	ft_putnbr(info->room_nb);
	ft_putstr("\n");
	ft_putstr("INDEX END : ");
	ft_putnbr(INDEX_END);
	ft_putstr("\n");
	ft_putstr("MAX_PATH : ");
	ft_putnbr(info->max_path);
	ft_putstr("\n");
	ft_putstr("first ptr : ");
	ft_putnbr((int)info->first);
	ft_putstr("\n");
	ft_putstr("start ptr : ");
	ft_putnbr((int)info->start);
	ft_putstr("\n");
	ft_putstr("end ptr : ");
	ft_putnbr((int)info->end);
	ft_putstr("\n");
	ft_putstr("START_COUNT : ");
	ft_putnbr(info->start_count);
	ft_putstr("\n");
	ft_putstr("end_count : ");
	ft_putnbr(info->end_count);
	ft_putstr("\n");
	ft_putstr("\n");
}

void	ft_show_path(t_info *info, t_path *lst)
{
	int i;
	t_path *path;

	path = lst;
	ft_putstr("---------------------SOLUTIONS--------------------\n");
	while (path)
	{
		if (path->flag == -1)
		{
			i = 0;
			while (i < ROOM_NB && path->path_index[i] != 0)
			{
				ft_putnbr((int)path->path_index[i]);
				ft_putstr(" | ");
				i++;
			}
			ft_putstr("\n");
			ft_putnbr((int)path->flag);
			ft_putstr("\n\n");
		}
		path = path->next;
	}
}

void	ft_show_best_sol(t_info *info)
{
	t_path *best_sol;
	int i;

	ft_putstr("TEST \n");
	best_sol = info->best_sol->first_path;
	ft_putstr("---------------------BEST SOLUTION--------------------\n");
	while (best_sol)
	{
		i = 0;
		while (i < ROOM_NB && best_sol->path_index[i] != 0)
		{
			ft_putnbr((int)best_sol->path_index[i]);
			ft_putstr(" | ");
			i++;
		}
		ft_putstr("\n\n");
	}
	best_sol = best_sol->next;
}
