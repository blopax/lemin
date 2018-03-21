/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:58:24 by atourner          #+#    #+#             */
/*   Updated: 2018/03/15 16:24:41 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lem.h"

t_room		*search_arrival(t_room *first, char *str)
{
	t_room	*act;
	char	*tmp;
	t_room	*ret;

	if (!first || !str)
	{
		if (str)
			ft_strdel(&str);
		return (0);
	}
	act = first;
	ret = NULL;
	while (act && !ret)
	{
		if (ft_strstr(str, act->name))
		{
			if (!(tmp = ft_delete_part(str, act->name)))
				ret = act;
			else
				ft_strdel(&tmp);
		}
		act = act->next;
	}
	ft_strdel(&str);
	return (ret);
}

int			free_if_needed(char *str)
{
	if (str)
		ft_strdel(&str);
	return (0);
}

int			start_link(t_room *first, char *str)
{
	t_room	*act;
	int		link;
	t_room	*out;

	if (!first)
		return (free_if_needed(str));
	act = first;
	link = 0;
	while (act)
	{
		if (ft_strstr(str, act->name))
		{
			if ((out = search_arrival(act->next,
							ft_delete_part(str, act->name))))
			{
				create_link(act, out);
				link++;
			}
		}
		act = act->next;
	}
	ft_strdel(&str);
	return (link);
}

char		*ft_delete_part(char *to_delete, char *search)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = ft_strstr(to_delete, search);
	if (tmp == to_delete)
	{
		if (!ft_strcmp(to_delete, search))
			return (NULL);
		else
		{
			while (to_delete[i] == search[i])
				i++;
			tmp = ft_strdup(&(to_delete[i + 1]));
		}
	}
	else
	{
		while (&to_delete[i + 1] != tmp)
			i++;
		tmp = ft_strndup(to_delete,
				(ft_strcmp(&to_delete[i + 1], search) ? i + 1 : i));
	}
	return (tmp);
}

void		do_link(t_room *first, char **room, int i)
{
	int		continu;

	continu = 1;
	while (room[i] && continu)
	{
		if (room[i][0] != '#')
			continu = start_link(first, ft_strdup(room[i]));
		else if (!ft_strcmp(room[i], "##start") || !ft_strcmp(room[i], "##end"))
			break ;
		i++;
	}
}
