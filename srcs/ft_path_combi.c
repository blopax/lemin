#include "../includes/header.h"

t_path		*ft_path_duplicate(t_info *info, t_path *path)
{
	t_path	*new_path;

	if (!(new_path = (t_path *)malloc(sizeof(t_path))))
		exit (0);
//	new_path->path_index = path->path_index;
	new_path->path_index = ft_intdup(path->path_index, ROOM_NB, 0);
	new_path->flag = path->flag;
	new_path->path_len = path->path_len;
	new_path->next = 0;
	return (new_path);
}

t_sol		*ft_init_sol(t_info *info, t_path *path)
{
	t_sol	*sol;

	if (!(sol = (t_sol*)malloc(sizeof(t_sol))))
		exit (0);
	sol->first_path = ft_path_duplicate(info, path);
	sol->last_path = sol->first_path;
	sol->path_nb = 1;
	sol->cycles = 0;
	sol->next = 0;
	return (sol);
}

t_sol	*ft_last_sol(t_sol *sol)
{
	t_sol	*sol_tmp;

	sol_tmp = sol;
	while (sol_tmp->next)
	{
		sol_tmp = sol_tmp->next;
	}
	return (sol_tmp);
}

t_sol		*ft_sol_duplicate(t_info *info, t_sol *sol, t_path *path)
{
	t_sol	*new_sol;
	t_path	*src_path_tmp;
	t_path	*dest_path_tmp;

	if (!(new_sol = (t_sol*)malloc(sizeof(t_sol))))
		exit (0);

	src_path_tmp = sol->first_path;
	new_sol->first_path = ft_path_duplicate(info, src_path_tmp);
	dest_path_tmp = new_sol->first_path;
	src_path_tmp = src_path_tmp->next;

	while (src_path_tmp)
	{
		dest_path_tmp->next = ft_path_duplicate(info, src_path_tmp);
		dest_path_tmp = dest_path_tmp->next;
		src_path_tmp = src_path_tmp->next;
	}
	dest_path_tmp->next = ft_path_duplicate(info, path);
	new_sol->last_path = dest_path_tmp->next;
	new_sol->path_nb = sol->path_nb++;
	new_sol->cycles = ft_cycles(info, sol);
	new_sol->last_path->next = 0;
	new_sol->next = 0;
	return (new_sol);
}

void	ft_count_exclusive_path(t_sol *sol, t_info *info)
{
	int		count;
	t_sol	*sol_tmp;
	t_path	*path_tmp;

	sol_tmp = sol;
	ft_putstr("------COUNT_EXCLUSIVE_PATH-------\n\n");
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
		{
			ft_putstr("BEST_SOL IS SET\n\n");
			info->best_sol = sol_tmp;
			ft_putstr("------COUNT_EXCLUSIVE_PATH-------\n\n");
			break ;
		}
		sol_tmp = sol_tmp->next;
	}
	ft_putstr("------COUNT_EXCLUSIVE_PATH-------\n\n");
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

void	ft_sol_combine_to_existing(t_info *info, t_path *path)
{
	t_sol	*sol_tmp;
	t_sol	*last_preexisting_sol;

	last_preexisting_sol = ft_last_sol(info->sol_first);
	sol_tmp = info->sol_first;
	while (sol_tmp)
	{
		if (ft_check_exclusive_path(sol_tmp, path, info) == 0)
		{
			ft_last_sol(info->sol_first)->next = ft_sol_duplicate(info, sol_tmp, path);
		}
		if (sol_tmp == last_preexisting_sol)
			break ;
		sol_tmp = sol_tmp->next;
	}
	ft_last_sol(sol_tmp)->next = ft_init_sol(info, path);
}

void	ft_show_sol(t_info *info, t_sol *sol)
{
	t_sol *sol_tmp;
	t_path *sol_path_tmp;
	int i;

	i = 0;
	sol_tmp = sol;
	ft_putstr("---------------LISTE SOL-------------\n\n");
//	while (sol_tmp)
//	{
		sol_path_tmp = sol_tmp->first_path;
		ft_putstr("////////////////////////\n");
		while (sol_path_tmp)
		{
			i = 0;
			while (i < ROOM_NB && sol_path_tmp->path_index[i] != 0)
			{
				ft_putnbr((int)sol_path_tmp->path_index[i]);
				ft_putstr(" | ");
				i++;
			}
			ft_putstr("\n");
			ft_putstr("PATH_LEN :\t");
			ft_putnbr((int)sol_path_tmp->path_len);
			ft_putstr("\n\n");
			sol_path_tmp = sol_path_tmp->next;
		}
		ft_putstr("////////////////////////\n");
//		sol_tmp = sol_tmp->next;
//	}
	ft_putstr("---------------LISTE SOL-------------\n\n");
}

void	ft_sol_list(t_info *info)
{
	t_path	*path_tmp;

	path_tmp = PATH;
	while (path_tmp)
	{
		if (path_tmp->flag == 0)
		{
			if (!info->sol_first)
			{
				info->sol_first = ft_init_sol(info, path_tmp);
			}
			else
			{
				ft_sol_combine_to_existing(info, path_tmp);
			}
			path_tmp->flag = -1;
		}
		path_tmp = path_tmp->next;
	}
	//	return (info->sol_first);
}

// marche pour le premier tour recusrsive nico pas pour la suite (il faut recombiner aux preexistants)
