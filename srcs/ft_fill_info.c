/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:27:44 by pclement          #+#    #+#             */
/*   Updated: 2018/03/15 15:49:44 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_sharp_treatment(char *line, t_info *info)
{
	if (line[1] == '#')
	{
		CMD = ft_safe_free(CMD);
		CMD = ft_strdup(line + 2);
	}
	if (ft_strcmp(CMD, "start") == 0)
		START_COUNT++;
	if (ft_strcmp(CMD, "end") == 0)
		END_COUNT++;
	if (START_COUNT > 1 || END_COUNT > 1 || (PHASE == 1 && (START_COUNT > 0 || END_COUNT > 0)))
		return(1);
	return (0);
}

int		ft_fill_info_p1(char *line, t_info *info)
{
	int		i;

	i = 0;
	if (line[0] == '#')
		return (ft_sharp_treatment(line, info));
	while (line[i] != 0)
	{
		if (ft_isdigit(line[i] == 0))
			return (1);
		i++;
	}
	ANT_NB = ft_atoi(line);
	if (ANT_NB < 1)
		return (1);
	PHASE = 2;
	return (0);
}

int		ft_fill_info_p2(char *line, t_info *info)
{
	if (line[0] == '#')
		return (ft_sharp_treatment(line, info));
	if (ft_strchr(line, '-') != 0)
	{
		PHASE = 3;
		return (ft_fill_info(line, info));
	}
	if (ft_check_p2(line, info) == 1)
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

int		ft_fill_info_p3(char *line, t_info *info)
{
	char*	room1;
	char*	room2;
	int		i;

	if (line[0] == '#')
		return (ft_sharp_treatment(line, info));
	if (ft_strchr(line, '-') == 0 || ft_strchr(line, '-') != ft_strrchr(line, '-'))
		return (1);
	room2 = ft_strchr(line,'-') + 1;
	i = 0;
	while (line[i] != '-')
		i++;
	line[i] = 0;
	room1 = line;
	if (room1[0] == 0 || room2[0] == 0)
		return (1);
	else
		return (ft_link_rooms(info, room1, room2));
}

int		ft_fill_info(char *line, t_info *info)
{
	if (PHASE == 1)
		return (ft_fill_info_p1(line, info));
	if (PHASE == 2)
		return (ft_fill_info_p2(line, info));
	if (PHASE == 3)
		return (ft_fill_info_p3(line, info));
	return (0);
}
