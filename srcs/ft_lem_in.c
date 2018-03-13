/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:53:35 by pclement          #+#    #+#             */
/*   Updated: 2018/03/13 18:20:22 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_check_input(char *line, t_info *info)
{
	int blank;

	blank = 0;
	SIZE = ft_strlen(line) - 1;
	if (ft_isdigit(line[SIZE]) == 0 || SIZE < 5)
		return (1);
	while (blank < 2 && line[SIZE])
	{
		if (line[SIZE] != ' ' && ft_isdigit(line[SIZE]) == 0)
			return (1);
		if (line[SIZE] == ' ')
			{
				blank++;
				if (blank == 1)
					Y_ROOM = ft_atoi(line + SIZE);
				if (blank == 2)
					X_ROOM = ft_atoi(line + SIZE);
			}
		if (blank < 2)
			SIZE--;
	}
	if (X_ROOM == -1 || Y_ROOM == -1)
		return (1);
	return (0);
}


int		ft_fill_info_p2(char *line, t_info *info)
{
	if (line[0] == '#')
		return (ft_sharp_treatment(line, info));
	if (ft_check_input(line, info) == 1)
		return (1);
	if (ft_strcmp(CMD, "start") == 0)
		ft_add_room(line, info, 1);
	else if (ft_strcmp(CMD, "end") == 0)
		ft_add_room(line, info, 2);
	else
		ft_add_room(line, info, 0);
	CMD = ft_safe_free(CMD);
	return (0);
}

int		ft_fill_info(char *line, t_info *info)
{
	if (PHASE == 1)
		ft_fill_info_p1(line, info);
	else if (PHASE == 2)
	{
		if (ft_fill_info_p2(line, info) == 1)
			return (1);
	}
	else if (PHASE == 3)
	{
		if (ft_fill_info_p3(line, info) == 1)
			return (1);
	}
	return (0);
}

int		main(int argc, char** argv)
{
	char	*line;
	t_info	*info;

	info = ft_info_init();
	while (get_next_line(0, &line) > 0 && TREAT_OVER == 0)
	{
		if (ft_fill_info(line, info) == 1)
			TREAT_OVER = 1;
		line = ft_safe_free(line);
	}
	if (ft_check_info(info) != 0)
		return (ft_error());
	ft_solve(info);
	ft_free_all(info);
	return (0);
}

