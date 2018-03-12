/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:27:44 by pclement          #+#    #+#             */
/*   Updated: 2018/03/12 16:41:36 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	treat 

void	ft_fill_info(char *line, t_info info)
{
	if (info.phase == 0)
		ft_info_fill_ants_nb(line, info);
	else if (info.phase == 1)
		ft_info_fill_room(line, info);
	else
		ft_fill_tubes(line, info);
}
