/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:53:35 by pclement          #+#    #+#             */
/*   Updated: 2018/04/06 18:29:16 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int		main(int argc, char **argv)
{
	char	*line;
	t_info	*info;

	argc = 0;
	(void)argv;
	info = ft_info_init();
	while (TREAT_OVER == 0 && get_next_line(0, &line) > 0)
	{
		if (ft_fill_info(line, info) == 1)
			TREAT_OVER = 1;
		line = ft_safe_free(line);
	}
	MAX_PATH = ft_max_path(info);
	if (ft_check_info(info) != 0 || START_COUNT != 1 || END_COUNT != 1 || MAX_PATH == 0)
	{
		ft_error();
		return (ft_free_all(info));
	}
	INDEX_END = END->index;
	if (ft_solve(info) == 1)
		return (ft_free_all(info));
	ft_move_ants(info);
	return (ft_free_all(info));
}
