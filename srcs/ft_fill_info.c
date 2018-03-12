/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:27:44 by pclement          #+#    #+#             */
/*   Updated: 2018/03/12 18:48:02 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_sharp_treatment(char *line, t_info *info)
{
	if (line[1] != '#')
		return (0);
	else 
		ft_command_treatment(line, info);
	return (0);
}

void		ft_link_rooms(t_info *info, char *room1, char *room2)
{
	t_room		*room_tmp;

	room_tmp = START;
	while (room_tmp)
	{
		if (ft_strcmp(room_tmp->name, room1) == 0)
			ft_add_linked_room(room_tmp->linked_room, room1);
		if (ft_strcmp(room_tmp->name, room2) == 0)
			ft_add_linked_room(room_tmp->linked_room, room2);
		room_tmp = room_tmp->next;
	}

}

int		ft_fill_info_p3(char *line, t_info *info)
{
	int		hyphen_count;
	char*	room1;
	char*	room2;
	int		i;


	if (line[0] == '#')
		return (ft_sharp_treatment(line, info));
	if (ft_strchr(line, '-') == 0 || ft_strchr(line, '-') != ft_strrchr(line, '-'))
	{
		info->treat_over = 1;
		return (0);
	}
	room2 = ft_strchr(line,'-') + 1;
	i = 0;
	while (line[i] != '-')
		i++;
	line[i] = 0;
	room1 = line;
	if (room1[0] == 0 || room2[0] == 0)
		info->treat_over = 1;
	else
		ft_link_rooms(info, room1, room2);
	return (0);
}
