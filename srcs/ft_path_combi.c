/*
   exp
Comb1 : P1 (length 3)
P2 len 3)
P3 (len 2)


Comb2 : P1 (length 4)
P2 len 4)
P3 (len 4)
P4 (len 4)

si moins de 16 fourmis C1 est meilleur sinon C2


si meme nb de chemin prendre somme des length
(id est P1 len 1 P2 len 7 et p3 len 3 idem que P1 len 2 P2 len 4 et P3 len 5)
attention depend nb fourmis si 2 fourmis le premier est meilleur 

sinon on balance vite algo a chaque Combinaison et on donne le nm de cycles pr le nb de fourmis en option. en gros on rajoute 1 par chemin au bout de longeur et on voit quand on est > ANT No


on peut partir de i = min len P pour chaque combinaison (comme ca si 100k fourmis et pmin = 1000 on incremente pas de 1 1000 fois


donc on a 
liste de combi de chemins exclusifs  avec
liste de chemins
longueur de chaque chemin
index des path? 
nb de cycle pr arriver a la fin

et ds info on met t_sol *solminimum ver la combi la plus optimum


rajouter chaque sol directement ac path_nb++
*/
#include "../includes/header.h"

t_cycles_info	*ft_cycles_init(t_info *info, t_sol *sol)
{
	t_cycles_info	*cycles_info;
	t_path			*tmp_path;
	int				i;

	if (!(cycles_info = (t_cycles_info *)ft_memalloc(sizeof(*cycles_info))))
		exit (0);

	if (!(cycles_info->len_tab = (int*)ft_memalloc((sizeof(int) * sol->path_nb))))
		exit (0);
	i = 0;
	tmp_path = sol->first_path;
	cycles_info->len_tab_min = tmp_path->path_len;
	cycles_info->len_tab_max = tmp_path->path_len;
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

int			ft_cycles(t_info *info, t_sol *sol)
{
	t_cycles_info	*cycles_info;
	int		i;
	int		arrived_ants;
	int		cycles;

	cycles_info = ft_cycles_init(info, sol);
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
	if (arrived_ants < ANT_NB)
		cycles = cycles + (ANT_NB - arrived_ants) / sol->path_nb + 1;
	free(cycles_info->len_tab);
	free(cycles_info);
	return (cycles);
}

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

t_sol	*ft_last(t_sol *sol)
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

t_sol		*ft_sol_duplicate(t_sol *sol, t_path *path)
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
	new_sol->cycles = 0;
	new_sol->next = 0;
	return (sol);
}

int		ft_sol_tmp(t_info *info, t_sol *sol)
{
	t_path	*path_tmp;

	if (sol->path_nb == MAX_PATH || sol->last_path == 0)
		return (1);
	path_tmp =  sol->last_path->next;

	while (path_tmp && path_tmp->flag == 0 && ft_check_exclusive_path(sol, path_tmp) != 0)
		path_tmp = path_tmp->next;
	if (path_tmp)
	{
		sol->next = ft_sol_duplicate(sol, path_tmp);
		sol = sol->next;
		sol->cycles = ft_cycles(info, sol);
		return (ft_sol_tmp(info, sol));
	}
	return (1);
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
		if (path_tmp->flag == 1)
		{
			sol_tmp = ft_init_sol(path_tmp);
			if (!info->sol_first)
				info->sol_first = sol_tmp;
			else
			{
				sol_last = ft_last(info->sol_first);
				sol_last->next = sol_tmp;
			}
			ft_sol_tmp(info, sol_tmp);
			path_tmp->flag = -1;
		}
		path_tmp = path_tmp->next;
	}
	return (sol_tmp);
}
