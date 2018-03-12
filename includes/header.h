#ifndef HEADER_H
# define HEADER_H
# define CMD info->command
# define TREAT_OVER info->treatment_over
# define PHASE info->phase
# define ANT_NB info->ant_nb
# define ROOM_NB info->room_nb
# define MAX_PATH info->max_path
# define START info->start
# define END info->end
# define X_ROOM info->x_room
# define Y_ROOM info->y_room
# define SIZE info->size
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
	char			*command;
	int				treatment_over;
	int				phase;
	int				ant_nb;
	int				room_nb;
	int				max_path;
	int				x_room;
	int				y_room;
	int				size;
	t_room			*start;
	t_room			*end;
	int				treat_over;
}					t_info;

t_info				*ft_info_init(void);
int					ft_sharp_treatment(char *line, t_info *info);
#endif
