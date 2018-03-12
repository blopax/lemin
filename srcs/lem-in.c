/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:53:35 by pclement          #+#    #+#             */
/*   Updated: 2018/03/12 16:21:13 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		main(int argc, char** argv)
{
	char	*line;
	int		fd;
	int		ret;
	t_info	info;

	if (argc != 2)
		return (ft_error());
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		return (ft_error());
	info = ft_info_init();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_info_fill(line, info.phase);
		free(line);
	}
	if (ft_check_info(info) != 0)
		return (ft_error());
	ft_solve(info);
	ft_free_all(info);
	return (0);
}

