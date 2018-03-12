/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:21:27 by nvergnac          #+#    #+#             */
/*   Updated: 2018/03/12 16:30:11 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define PHASE info->phase
# define ANT_NB info->ant_nb
# define ROOM_NB info->room_nb
# define MAX_PATH info->max_path
# define START info->start
# define END info->end
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_link
{
	char			*name;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	int				x;
	int				y;
	char			*name;
	t_link			*linked_room;
	struct s_room	*next;
}					t_room;

typedef	struct		s_info
{
	int				phase;
	int				ant_nb;
	int				room_nb;
	int				max_path;
	t_room			*start;
	t_room			*end;
}					t_info;

#endif
