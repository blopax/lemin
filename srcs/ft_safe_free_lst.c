/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:01:03 by nvergnac          #+#    #+#             */
/*   Updated: 2018/03/15 17:18:26 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free_lst_room(t_room *room_lst)
{
	t_room	*tmp;

	tmp = room_lst;
	while (room_lst)
	{
		tmp = room_lst->next;
		ft_safe_free(room_lst->name);
		free(room_lst);
		room_lst = tmp;
	}
}

void	ft_free_lst_link(t_link *link_lst)
{
	t_link *tmp;

	tmp = link_lst;
	while (link_lst)
	{
		tmp = link_lst->next;
		ft_safe_free(link_lst->name);
		free(link_lst);
		link_lst = tmp;
	}
}

void	ft_free_all(t_info *info)
{
	ft_free_lst_room(FIRST);
	FIRST = 0;
	START = 0;
	ft_safe_free(CMD);
	free(info);
	info = 0;
}
