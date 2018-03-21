/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:48:31 by atourner          #+#    #+#             */
/*   Updated: 2018/03/19 16:12:58 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

int			push_from_start(t_room *anthill, int act_ant, char *room_name)
{
	t_room		*act;
	t_link		*act_l;

	act = anthill;
	while (!act->start)
		act = act->next;
	act_l = act->link;
	while (act_l && ft_strcmp(act_l->room->name, room_name))
		act_l = act_l->next;
	if (!act_l || act_l->room->next_ant)
		return (0);
	if (act_l->room->end)
		act_l->room->act_ant += 1;
	else
		act_l->room->next_ant = act_ant;
	return (1);
}

int			push_from_room(t_room *act, int act_ant, char *room_name)
{
	t_link		*act_l;

	act_l = act->link;
	while (act_l && ft_strcmp(act_l->room->name, room_name))
		act_l = act_l->next;
	if (!act_l || act_l->room->next_ant)
		return (0);
	if (act_l->room->end)
		act_l->room->act_ant += 1;
	else
		act_l->room->next_ant = act_ant;
	return (1);
}

t_room		*search_ant(t_room *anthill, int act_ant)
{
	t_room		*ret;
	t_room		*act;

	ret = NULL;
	act = anthill;
	while (!ret && act)
	{
		if (act->act_ant == act_ant && !act->start && !act->end)
			ret = act;
		act = act->next;
	}
	return (ret);
}

char		*get_room_name(char *str)
{
	int		i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (&str[i + 1]);
}

int			possible_move(t_room *anthill, char *move)
{
	int		act_ant;
	t_room	*act;

	act_ant = ft_atoi(&move[1]);
	act = search_ant(anthill, act_ant);
	if (!act && !push_from_start(anthill, act_ant, get_room_name(&move[1])))
		return (0);
	else if (act && !push_from_room(act, act_ant, get_room_name(&move[1])))
		return (0);
	return (1);
}
