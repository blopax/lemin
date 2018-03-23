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
