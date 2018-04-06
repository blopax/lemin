/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:06:52 by nvergnac          #+#    #+#             */
/*   Updated: 2018/04/06 17:11:04 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	ft_putstr("START LINK ROOM COUNT : ");
	ft_putnbr(START->link_room_count);
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
			ft_putstr("\n");
			ft_putnbr((int)path->path_len);
			ft_putstr("\n\n");
		}
		path = path->next;
	}
}

void	ft_show_best_sol(t_info *info)
{
	t_path *best_sol;
	int i;

	best_sol = info->best_sol->first_path;
	ft_putstr("---------------------BEST SOLUTION--------------------\n\n");
	ft_putstr("NOMBRE DE CYCLES :\t");
	ft_putnbr((int)info->best_sol->cycles);
	ft_putstr("\n\n");
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
		ft_putstr("PATH_LEN :\t");
		ft_putnbr((int)best_sol->path_len);
		ft_putstr("\n\n");
		best_sol = best_sol->next;
	}
}

void	ft_show_sol(t_info *info, t_sol *sol)
{
	t_sol	*sol_tmp;
	t_path	*sol_path_tmp;
	int i;

	i = 0;
	sol_tmp = sol;
	ft_putstr("---------------LISTE SOL-------------\n\n");
//	while (sol_tmp)
//	{
		sol_path_tmp = sol_tmp->first_path;
		ft_putstr("////////////////////////\n");
		while (sol_path_tmp)
		{
			i = 0;
			while (i < ROOM_NB && sol_path_tmp->path_index[i] != 0)
			{
				ft_putnbr((int)sol_path_tmp->path_index[i]);
				ft_putstr(" | ");
				i++;
			}
			ft_putstr("\n");
			ft_putstr("PATH_LEN :\t");
			ft_putnbr((int)sol_path_tmp->path_len);
			ft_putstr("\n\n");
			sol_path_tmp = sol_path_tmp->next;
		}
		ft_putstr("\n");
		ft_putstr("CYCLES :\t");
		ft_putnbr((int)sol_tmp->cycles);
		ft_putstr("\n");
		ft_putstr("////////////////////////\n");
//		sol_tmp = sol_tmp->next;
//	}
	ft_putstr("---------------LISTE SOL-------------\n\n");
}
