/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:41:55 by nvergnac          #+#    #+#             */
/*   Updated: 2018/04/10 15:41:58 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_info_init_bis(t_info *info)
{
	START = 0;
	END = 0;
	PATH = 0;
	START_COUNT = 0;
	END_COUNT = 0;
	EX_SOL = 0;
	FLAG = 1;
	info->sol_first = 0;
	BEST_SOL = 0;
	info->path_repart = 0;
	ANT_TAB = 0;
	info->print_count = 0;
	LIMIT = 0;
}

t_info	*ft_info_init(void)
{
	t_info	*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		exit(0);
	CMD = 0;
	INPUT = 0;
	TREAT_OVER = 0;
	PHASE = 1;
	ANT_NB = 0;
	ROOM_NB = 0;
	MAX_PATH = 0;
	INDEX = 0;
	INDEX_END = 0;
	X_ROOM = -1;
	Y_ROOM = -1;
	SIZE = 0;
	FIRST = ft_room_init(-1, -1, 0, 0);
	ft_info_init_bis(info);
	return (info);
}
