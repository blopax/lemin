/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:50:45 by atourner          #+#    #+#             */
/*   Updated: 2018/03/07 13:26:45 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

#include <stdbool.h>

typedef struct	s_position
{
	int		x;
	int		y;
}				t_position;

typedef struct	s_link
{
	struct s_room		*room;
	struct s_link		*next;
}				t_link;

typedef struct	s_room
{
	char				*name;
	t_position			position;
	int					start;
	int					act_ant;
	bool				end;
	struct s_room		*next;
	struct s_room		*parent;
	struct s_link		*link;
}				t_room;

t_room			*ft_get_anthill();
t_room			*create_room(char *to_parse, int *command, int ant_nb);
void			free_all_room(t_room *first);
char			*ft_delete_part(char *to_delete, char *search);
int				start_link(t_room *first, char *str);
int				valid_room(char *tmp);
int				get_ant_nb(char **to_get);
void			get_command(char *str, int *command);
void			do_link(t_room *first, char **room, int i);
int				test_anthill(t_room *first);
void			create_link(t_room *entry, t_room *out);
int				no_way_to_end(t_room *first);

#endif
