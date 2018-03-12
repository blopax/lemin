/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:53:35 by pclement          #+#    #+#             */
/*   Updated: 2018/03/12 16:42:59 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char** argv)
{
	char	*line;
	t_info	*info;

	info = ft_info_init();
	while (get_next_line(0, &line) > 0)
	{
		ft_fill_info(line, info);
		line = ft_safe_free(line);
	}
	if (ft_check_info(info) != 0)
		return (ft_error());
	ft_solve(info);
	ft_free_all(info);
	return (0);
}

