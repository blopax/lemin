/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:21:27 by nvergnac          #+#    #+#             */
/*   Updated: 2018/03/12 15:35:30 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <unistd.h>
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
	int				ant_nb;
	int				room_nb;
	int				max_path;
	t_room			*start;
	t_room			*end;
}					t_info;

#endif
