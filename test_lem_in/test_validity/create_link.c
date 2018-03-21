/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:35:53 by atourner          #+#    #+#             */
/*   Updated: 2018/03/15 12:45:58 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

static void		new_link(t_link *link, t_room *to_add)
{
	t_link	*act;

	act = link;
	while (act->next)
	{
		if (!strcmp(act->room->name, to_add->name))
			return ;
		act = act->next;
	}
	if (!strcmp(act->room->name, to_add->name))
		return ;
	if (!(act->next = ft_memalloc(sizeof(t_link))))
		return ;
	act->next->room = to_add;
}

void			create_link(t_room *entry, t_room *out)
{
	if (!entry->link)
	{
		if (!(entry->link = ft_memalloc(sizeof(t_link))))
			return ;
		entry->link->room = out;
	}
	else
		new_link(entry->link, out);
	if (!out->link)
	{
		if (!(out->link = ft_memalloc(sizeof(t_link))))
			return ;
		out->link->room = entry;
	}
	else
		new_link(out->link, entry);
}
