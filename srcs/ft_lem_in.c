/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:53:35 by pclement          #+#    #+#             */
/*   Updated: 2018/03/26 19:53:21 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
int		ft_count_lst(t_room *room, int flag)
{
	int		i;
	t_room	*tmp_room;
	t_link	*tmp_link;

	i = 0;
	tmp_room = room;
	if (flag == 1)
	{
		while (tmp_room)
		{
			tmp_room->link_room_count = ft_count_lst(tmp_room, 2);
			tmp_room = tmp_room->next;
			i++;
		}
	}
	else if (flag == 2)
	{
		while (room->linked_room)
			i++;
	}
	return (i);
}
*/

int		ft_max_path(t_info *info)
{
	if (!(info && START && END))
		return (0);
	if (ANT_NB <= START->link_room_count && ANT_NB <= END->link_room_count)
		return (ANT_NB);
	if (START->link_room_count <= END->link_room_count)
		return (START->link_room_count);
	else
		return (END->link_room_count);
}

int		ft_error(void)
{
	write(2, "ERROR\n", 6);
	return (1);
}

int		ft_check_info(t_info *info)
{
	if (PHASE < 3)
		return (1);
	if (!START || !END)
		return (1);
	if ((START && START->linked_room == 0) || (END && END->linked_room == 0))
		return (1);
	return (0);
}
// si on met end ds sinfo on peut aussi checker si end n a pas de linked rooms

int		main(int argc, char **argv)
{
	char	*line;
	t_info	*info;

	argc = 0;
	(void)argv;
	info = ft_info_init();
	while (get_next_line(0, &line) > 0 && TREAT_OVER == 0)
	{
		if (ft_fill_info(line, info) == 1)
			TREAT_OVER = 1;
		line = ft_safe_free(line);
	}
	MAX_PATH = ft_max_path(info);
	ft_show_lst_room(FIRST);
	if (ft_check_info(info) != 0 || START_COUNT != 1 || END_COUNT != 1 || MAX_PATH == 0)
		return (ft_error());
	INDEX_END = END->index;
	ft_show_info(info);
	sleep(2);
	ft_solve(info);
	ft_show_path(info, PATH);
	ft_putstr("_______________FREE\n");
	ft_free_all(info);
	return (0);
}
