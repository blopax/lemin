#ifndef HEADER_H
# define HEADER_H
# define CMD info->command
# define TREAT_OVER info->treatment_over
# define PHASE info->phase
# define ANT_NB info->ant_nb
# define ROOM_NB info->room_nb
# define MAX_PATH info->max_path
# define FIRST info->first
# define START info->start
# define START_COUNT info->start_count
# define END_COUNT info->end_count
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
	int				type;
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
	t_room			*first;
	t_room			*start;
	int				start_count;
	int				end_count;
	int				treat_over;
}					t_info;

t_info				*ft_info_init(void);
int					ft_fill_info(char *line, t_info *info);
int					ft_sharp_treatment(char *line, t_info *info);
void				ft_add_linked_room(t_link *linked_room, char *room_name);
t_room				*ft_room_init(void);
void				ft_add_room(char *line, t_info *info, int type);
int					ft_check_p2(char *line, t_info *info);
int					ft_link_rooms(t_info *info, char *room1, char *room2);
void				ft_show_lst_room(t_room *lst);
#endif
