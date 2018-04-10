/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cycles_treatment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:23:01 by nvergnac          #+#    #+#             */
/*   Updated: 2018/04/10 15:25:30 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_cycles_info	*ft_cycles_init(t_sol *sol)
{
	t_cycles_info	*cycles_info;
	t_path			*tmp_path;
	int				i;

	if (!(cycles_info = (t_cycles_info *)malloc(sizeof(*cycles_info))))
		exit(0);
	if (!(cycles_info->len_tab = (int*)malloc((sizeof(int) * sol->path_nb))))
		exit(0);
	i = 0;
	tmp_path = sol->first_path;
	cycles_info->len_tab_min = tmp_path->path_len - 1;
	cycles_info->len_tab_max = tmp_path->path_len - 1;
	while (tmp_path)
	{
		cycles_info->len_tab[i] = tmp_path->path_len;
		if (tmp_path->path_len < cycles_info->len_tab_min)
			cycles_info->len_tab_min = tmp_path->path_len;
		if (tmp_path->path_len > cycles_info->len_tab_max)
			cycles_info->len_tab_max = tmp_path->path_len;
		i++;
		tmp_path = tmp_path->next;
	}
	return (cycles_info);
}

int				ft_cycles(t_info *info, t_sol *sol)
{
	t_cycles_info	*cycles_info;
	int				i;
	int				arrived_ants;
	int				cycles;

	cycles_info = ft_cycles_init(sol);
	cycles = cycles_info->len_tab_min;
	arrived_ants = 0;
	while (arrived_ants < ANT_NB && cycles < cycles_info->len_tab_max)
	{
		i = 0;
		while (i < sol->path_nb)
		{
			if (cycles >= cycles_info->len_tab[i])
				arrived_ants++;
			i++;
		}
		cycles++;
	}
	i = ((ANT_NB - arrived_ants) % sol->path_nb == 0 ? 0 : 1);
	if (arrived_ants < ANT_NB)
		cycles = (cycles - 1) + ((ANT_NB - arrived_ants) / sol->path_nb) + i;
	free(cycles_info->len_tab);
	free(cycles_info);
	return (cycles);
}
