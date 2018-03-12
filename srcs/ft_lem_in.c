/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:53:35 by pclement          #+#    #+#             */
/*   Updated: 2018/03/12 18:12:41 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_check_command(char *line, t_info *info)
{
	if (ft_strncmp("##", line, 2) == 0)
}

int		ft_fill_info_p2(char *line, t_info *info)
{
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

