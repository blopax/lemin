/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:53:35 by pclement          #+#    #+#             */
/*   Updated: 2018/03/15 16:04:02 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_error(void)
{
	write(1, "ERROR\n", 6);
	return (1);
}

int		ft_check_info(t_info *info)
{
	if (PHASE < 3)
		return (1);
	if (START && START->linked_room == 0)
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
	if (ft_check_info(info) != 0)
		return (ft_error());
//	ft_solve(info);
//	ft_free_all(info);
	return (0);
}

