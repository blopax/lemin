/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:53:35 by pclement          #+#    #+#             */
/*   Updated: 2018/04/10 16:43:54 by nvergnac         ###   ########.fr       */
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

int		ft_error(t_info *info)
{
	write(2, "ERROR\n", 6);
	return (ft_free_all(info));
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

void	ft_get_info(t_info *info)
{
	char	*line;
	char	*tmp;

	tmp = 0;
	line = 0;
	while (TREAT_OVER == 0 && get_next_line(0, &line) > 0)
	{
		tmp = ft_strdup(INPUT);
		INPUT = ft_safe_free(INPUT);
		INPUT = ft_strjoin(tmp, line);
		tmp = ft_safe_free(tmp);
		tmp = ft_strdup(INPUT);
		INPUT = ft_safe_free(INPUT);
		INPUT = ft_strjoin(tmp, "\n");
		if (ft_fill_info(line, info) == 1)
			TREAT_OVER = 1;
		line = ft_safe_free(line);
		tmp = ft_safe_free(tmp);
	}
	MAX_PATH = ft_max_path(info);
}

int		main(void)
{
	t_info	*info;

	info = ft_info_init();
	ft_get_info(info);
	if (ft_check_info(info) != 0 || START_COUNT != 1 || END_COUNT != 1 ||
			MAX_PATH == 0)
		return (ft_error(info));
	INDEX_END = END->index;
	if (ft_solve(info) == 1)
		return (ft_error(info));
	ft_putstr(INPUT);
	ft_putstr("\n");
	ft_move_ants(info);
	return (ft_free_all(info));
}
