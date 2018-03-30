/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_combi_utilities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:20:26 by nvergnac          #+#    #+#             */
/*   Updated: 2018/03/30 20:04:32 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_sol	*ft_last_sol(t_sol *sol)
{
	t_sol	*sol_tmp;

	sol_tmp = sol;
	if (sol_tmp)
	{
		while (sol_tmp->next)
			sol_tmp = sol_tmp->next;
		return (sol_tmp);
	}
	return (0);
}

void	ft_set_best_sol(t_info *info)
{
	t_sol	*sol_tmp;
	int		min_cycles;

	sol_tmp = info->sol_first;
	min_cycles = sol_tmp->cycles;
	while (sol_tmp)
	{
		if (sol_tmp->cycles < min_cycles)
		{
			min_cycles = sol_tmp->cycles;
			info->best_sol = sol_tmp;
		}
		sol_tmp = sol_tmp->next;
	}
}

void	ft_count_exclusive_path(t_sol *sol, t_info *info)
{
	int		count;
	t_sol	*sol_tmp;
	t_path	*path_tmp;

	sol_tmp = sol;
	while (sol_tmp)
	{
		count = 0;
		path_tmp = sol_tmp->first_path;
		while (path_tmp)
		{
			count++;
			path_tmp = path_tmp->next;
		}
		if (count > EX_SOL)
			EX_SOL = count;
		if (EX_SOL == MAX_PATH)
			break ;
		sol_tmp = sol_tmp->next;
	}
}

int		ft_check_exclusive_path(t_sol *sol, t_path *path, t_info *info)
{
	t_path	*sol_path_tmp;
	t_path	*path_tmp;
	int i;
	int k;

	sol_path_tmp = sol->first_path;
	path_tmp = path;
	while (sol_path_tmp)
	{
		i = 1;
		while ((sol_path_tmp->path_index[i] != INDEX_END && sol_path_tmp->path_index[i] != 0))
		{
			k = 0;
			while (path->path_index[k] != 0 && k < ROOM_NB)
			{
				if (sol_path_tmp->path_index[i] == path->path_index[k])
					return (1);
				k++;
			}
			i++;
		}
		sol_path_tmp = sol_path_tmp->next;
	}
	return (0);
}

