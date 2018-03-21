/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:52:50 by atourner          #+#    #+#             */
/*   Updated: 2018/03/19 16:08:12 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"
#include <fcntl.h>

int		all_move_done(t_room *anthill, char *to_split)
{
	char	**split_done;
	int		i;
	int		j;
	int		ant_this_turn[1000];

	i = 0;
	split_done = ft_strsplit_space(to_split);
	while (split_done[i])
	{
		ant_this_turn[i] = (ft_atoi(&split_done[i][1]));
		if (!ant_this_turn[i] || !possible_move(anthill, split_done[i]))
			return (0);
		if (check_double(ant_this_turn, i))
			return (0);
		i++;
	}
	return (1);
}

int		all_ant_arrived(t_room *anthill)
{
	t_room	*act;
	int		arrived;
	int		start;

	act = anthill;
	arrived = 0;
	start = 0;
	while (act && (!start || !arrived))
	{
		if (act->start)
			start = act->start;
		if (act->end)
			arrived = act->act_ant;
		act = act->next;
	}
	if (start == arrived)
		return (1);
	return (0);
}

void	reset_next_ant(t_room *anthill)
{
	t_room	*act;

	act = anthill;
	while (act)
	{
		if (!act->end)
		{
			act->act_ant = act->next_ant;
			act->next_ant = 0;
		}
		act = act->next;
	}
}

int		check_answer(t_room *anthill)
{
	char	*tmp;
	int		fd;

	fd = open("ant", O_RDONLY);
	while (get_next_line(fd, &tmp))
	{
		if (!all_move_done(anthill, tmp))
			return (0);
		reset_next_ant(anthill);
		free(tmp);
	}
	if (all_ant_arrived(anthill))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_room		*anthill;

	anthill = ft_get_anthill();
	if (!anthill)
		ft_printf("ERROR\n");
	else
	{
		if (check_answer(anthill))
			ft_printf("\033[0;32m🀫\033[0;0m");
		else
		{
			ft_printf("\033[0;31m🀫\033[0;0m");
			error_gestion(av[1]);
		}
	}
	free_all_room(anthill);
	return (0);
}
