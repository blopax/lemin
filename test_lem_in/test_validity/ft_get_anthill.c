/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_anthill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:30:29 by atourner          #+#    #+#             */
/*   Updated: 2018/03/19 11:22:22 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
#include "ft_printf.h"

static char		**realloc_ar(char **tmp, char **act, int nb)
{
	char		**new;
	int			to_cpy;

	if (!(new = (char**)malloc(sizeof(char*) * (nb + 1))))
		return (NULL);
	to_cpy = -1;
	while (++to_cpy < nb - 1)
		new[to_cpy] = ft_strdup(act[to_cpy]);
	new[to_cpy] = ft_strdup(*tmp);
	new[to_cpy + 1] = NULL;
	if (act)
		ft_free_ar((void**)act);
	ft_strdel(tmp);
	return (new);
}

static void		parse_room(char *to_parse, t_room **first,
		int *command, int ant_nb)
{
	t_room	*act;

	if (!*first)
		*first = create_room(to_parse, command, ant_nb);
	else
	{
		act = *first;
		while (act->next)
			act = act->next;
		act->next = create_room(to_parse, command, ant_nb);
	}
}

static	t_room	*parse(char **room, int command, int ant_nb)
{
	t_room		*ret;
	int			i;
	int			need_parse;

	i = -1;
	ret = NULL;
	while (ant_nb > 0 && room[++i])
	{
		if (!(need_parse = valid_room(room[i])) || command == -1)
		{
			if (!command && start_link(ret, ft_strdup(room[i]))
					&& test_anthill(ret))
				break ;
			free_all_room(ret);
			ret = NULL;
			break ;
		}
		if (need_parse != 2)
			parse_room(room[i], &ret, &command, ant_nb);
		else
			get_command(room[i], &command);
	}
	if (ret)
		do_link(ret, room, i);
	return (ret);
}

t_room			*ft_get_anthill(void)
{
	char	*tmp;
	int		ant_nb;
	char	**act;
	t_room	*first;
	int		nb;

	nb = 0;
	ant_nb = 0;
	act = NULL;
	first = NULL;
	while (!ant_nb && get_next_line(0, &tmp))
		ant_nb = get_ant_nb(&tmp);
	while (get_next_line(0, &tmp))
		act = realloc_ar(&tmp, act, ++nb);
	if (act)
		first = parse(act, 0, ant_nb);
	ft_free_ar((void**)act);
	return (first);
}
