/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_struct_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 13:56:56 by atourner          #+#    #+#             */
/*   Updated: 2018/03/15 15:23:00 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

static void	add_start_and_end(t_room *new, int *command, int ant_nb)
{
	if (*command == 1)
	{
		new->start = ant_nb;
		*command = 0;
	}
	else if (*command == 2)
	{
		new->end = 1;
		*command = 0;
	}
}

t_room		*create_room(char *to_parse, int *command, int ant_nb)
{
	t_room		*new;
	int			i;

	i = (int)ft_strlen(to_parse);
	if (!(new = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	ft_bzero(new, sizeof(t_room));
	while (ft_isdigit(to_parse[--i]))
		;
	new->position.y = ft_atoi(&to_parse[i + 1]);
	while (ft_isdigit(to_parse[--i]))
		;
	new->position.x = ft_atoi(&to_parse[i + 1]);
	new->name = ft_strndup(to_parse, i);
	if (*command)
		add_start_and_end(new, command, ant_nb);
	return (new);
}

void		free_room(t_room *act)
{
	t_link		*nextl;
	t_link		*actl;

	if (act->name)
		ft_strdel(&act->name);
	if ((actl = act->link))
	{
		nextl = actl->next;
		while (actl)
		{
			free(actl);
			actl = nextl;
			if (nextl)
				nextl = nextl->next;
		}
	}
	ft_bzero(act, sizeof(t_room));
	free(act);
}

void		free_all_room(t_room *first)
{
	t_room	*next;

	next = first;
	while (first)
	{
		next = first->next;
		free_room(first);
		first = next;
	}
}

void		free_room_if(t_room *open, t_room *closed)
{
	t_room		*act_o;
	t_room		*act_c;
	t_room		*tmp;

	act_c = closed;
	while (act_c)
	{
		act_o = open;
		tmp = act_c->next;
		while (act_o)
		{
			if (!ft_strcmp(act_o->name, act_c->name))
				break ;
			else if (!act_o->parent)
				free_room(act_c);
			act_o = act_o->parent;
		}
		act_c = tmp;
	}
}
