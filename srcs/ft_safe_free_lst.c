/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:01:03 by nvergnac          #+#    #+#             */
/*   Updated: 2018/04/06 19:13:05 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free_lst_link(t_link *link_lst)
{
	t_link *tmp;

	tmp = link_lst;
	while (link_lst)
	{
		tmp = link_lst->next;
		ft_safe_free(link_lst->name);
		free(link_lst);
		link_lst = 0;
		link_lst = tmp;
	}
}

void	ft_free_lst_room(t_room *room_lst)
{
	t_room	*tmp;

	tmp = room_lst;
	while (room_lst)
	{
		tmp = room_lst->next;
		ft_safe_free(room_lst->name);
		ft_free_lst_link(room_lst->linked_room);
		free(room_lst);
		room_lst = 0;
		room_lst = tmp;
	}
}

void	ft_free_lst_path(t_info *info, t_path *path_lst)
{
	t_path	*path_tmp;
	int i;

	i = ROOM_NB;
	path_tmp = path_lst;
	while (path_lst)
	{
		path_tmp = path_lst->next;
		ft_bzero(path_lst->path_index, sizeof(int) * ROOM_NB);
		if (path_lst->path_index)
		{
			free(path_lst->path_index);
			path_lst->path_index = 0;
		}
		if (path_lst)
			free(path_lst);
		path_lst = path_tmp;
	}
}

void	ft_free_lst_sol(t_info *info, t_sol *sol_lst)
{
	t_sol	*sol_tmp;
	int i;

	i = ROOM_NB;
	sol_tmp = sol_lst;
	while (sol_lst)
	{
		sol_tmp = sol_lst->next;
		ft_free_lst_path(info, sol_lst->first_path);
		sol_lst->first_path = 0;
		sol_lst->last_path = 0;
		free(sol_lst);
		sol_lst = 0;
		sol_lst = sol_tmp;
	}
}

int		ft_free_all(t_info *info)
{
	ft_free_lst_room(FIRST);
	ft_free_lst_sol(info, info->sol_first);
	ft_free_lst_path(info, PATH);
	free(ANT_TAB);
	ANT_TAB = 0;;
	free(info->path_repart);
	ft_safe_free(CMD);
	ft_safe_free(INPUT);
	free(info);
	info = 0;
	return (0);
}
