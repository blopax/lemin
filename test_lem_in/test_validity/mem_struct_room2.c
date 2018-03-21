/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_struct_room2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:45:10 by atourner          #+#    #+#             */
/*   Updated: 2018/03/15 14:18:36 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

static void		free_link(t_room *act, t_link **act_l, t_link *bef)
{
	if (*act_l == act->link)
	{
		act->link = (*act_l)->next;
		bef = act->link;
	}
	else
	{
		bef = act->link;
		while (bef->next != *act_l)
			bef = bef->next;
		bef->next = (*act_l)->next;
	}
	free(*act_l);
	*act_l = bef;
}

static void		free_link_used(t_room *anthill, char *name_of_free)
{
	t_room	*act;
	t_link	*bef;
	t_link	*act_l;

	bef = NULL;
	act = anthill;
	while (act)
	{
		act_l = act->link;
		while (act_l)
		{
			if (!ft_strcmp(act_l->room->name, name_of_free))
				free_link(act, &act_l, bef);
			if (act_l)
				act_l = act_l->next;
		}
		act = act->next;
	}
}

static void		start_and_end_link(t_room *anthill, t_room *way)
{
	t_room		*act_w;
	t_room		*act;
	t_link		*act_l;
	t_link		*old;

	act_w = way;
	while (act_w)
	{
		act = anthill;
		while (ft_strcmp(act->name, act_w->name))
			act = act->next;
		act_l = act->link;
		old = act_l;
		while (!act_l->room->end && !act_l->room->start)
		{
			old = act_l;
			act_l = act_l->next;
		}
		old->next = act_l->next;
		if (act_l == act->link && !act_l->next)
			act->link = NULL;
		free(act_l);
		act_w = act_w->next;
	}
}

static void		basic_way(t_room *anthill, t_room *act_w,
		t_room *save, t_room *act)
{
	while (act_w)
	{
		act = anthill;
		while (act)
		{
			if (!ft_strcmp(act->name, act_w->name))
			{
				save = anthill;
				if (act != anthill)
					while (save->next != act)
						save = save->next;
				if (!act->end && !act->start)
				{
					free_link_used(anthill, act_w->name);
					save->next = act->next;
					free_room(act);
					act = save;
				}
			}
			act = act->next;
		}
		act_w = act_w->next;
	}
}

void			free_room_used(t_room *anthill, t_room *way)
{
	t_room		*save;
	t_room		*act_w;
	t_room		*act;

	act_w = way;
	save = NULL;
	act = NULL;
	if (way->start && way->next->end)
		start_and_end_link(anthill, way);
	else
		basic_way(anthill, act_w, save, act);
}
