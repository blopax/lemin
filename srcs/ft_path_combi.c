#include "../includes/header.h"


t_sol		*ft_init_sol(t_path *path)
{
	t_sol	*sol;

	if (!(sol = ft_memalloc(sizeof(t_sol))))
		exit (0);
	sol->first_path = path;
	sol->last_path = path;
	sol->path_nb = 1;
	sol->cycles = 0;
	return (sol);
}

t_sol	*ft_last_sol(t_sol *sol)
{
	t_sol	*sol_tmp;

	sol_tmp = sol;
	while (sol_tmp)
		sol_tmp = sol_tmp->next;
	return (sol_tmp);
}

t_path		*ft_path_duplicate(t_path *path)
{
	t_path	*new_path;

	if (!(new_path = ft_memalloc(sizeof(t_path))))
		exit (0);
	new_path->path_index = path->path_index;
	new_path->flag = path->flag;
	new_path->path_len = path->path_len;
	new_path->next = 0;
	return (new_path);
}

t_sol		*ft_sol_duplicate(t_info *info, t_sol *sol, t_path *path)
{
	t_sol	*new_sol;
	t_path	*src_path_tmp;
	t_path	*dest_path_tmp;

	if (!(new_sol = ft_memalloc(sizeof(t_sol))))
		exit (0);

	src_path_tmp = sol->first_path;
	new_sol->first_path = ft_path_duplicate(src_path_tmp);
	dest_path_tmp = new_sol->first_path;
	src_path_tmp = src_path_tmp->next;

	while (src_path_tmp)
	{
		dest_path_tmp->next = ft_path_duplicate(src_path_tmp);
		dest_path_tmp = dest_path_tmp->next;
		src_path_tmp = src_path_tmp->next;
	}
	dest_path_tmp->next = ft_path_duplicate(path);
	new_sol->last_path = dest_path_tmp->next;
	new_sol->path_nb = sol->path_nb++;
	new_sol->cycles = ft_cycles(info, sol);
	new_sol->next = 0;
	return (sol);
}

/*int		ft_sol_add(t_info *info, t_sol *sol)
{
	t_path	*path_tmp;

	if (sol->path_nb == MAX_PATH || sol->last_path == 0)
		return (1);
	path_tmp =  sol->last_path->next;

	while (path_tmp)
	{
		if (path_tmp->flag == 0 && ft_check_exclusive_path(sol, path_tmp) == 0)
		{
			sol->next = ft_sol_duplicate(info, sol, path_tmp);
			sol = sol->next;
			return (ft_sol_add(info, sol));
		}
		path_tmp = path_tmp->next;
	}
	return (1);
}*/

void	ft_sol_combine_to_existing(t_info *info, t_path *path)
{
	t_sol	*sol_tmp;
	t_sol	*last_preexisting_sol;

	last_preexisting_sol = ft_last_sol(info->sol_first);
	sol_tmp = info->sol_first;
	while (sol_tmp)
	{
		if (ft_check_exclusive_path(sol_tmp, path) == 0)
			ft_last_sol(info->sol_first)->next = ft_sol_duplicate(info, sol_tmp, path);
		if (sol_tmp == last_preexisting_sol)
			break ;
		sol_tmp = sol_tmp->next;
	}
	ft_last_sol(sol_tmp)->next = ft_init_sol(path);
}

t_sol		*ft_sol_list(t_info *info)
{
	t_path	*path_tmp;
	t_path	*sol_path_tmp;
	t_sol	*sol_tmp;
	t_sol	*sol_last;

	path_tmp = PATH;
	while (path_tmp)
	{
		if (path_tmp->flag == 0)
		{
			if (!info->sol_first)
				info->sol_first = ft_init_sol(path_tmp);
			else
				ft_sol_combine_to_existing(info, path_tmp);
			path_tmp->flag = -1;
		}
		path_tmp = path_tmp->next;
	}
	return (info->sol_first);
}

// marche pour le premier tour recusrsive nico pas pour la suite (il faut recombiner aux preexistants)
