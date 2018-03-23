#ifndef HEADER_H
# define HEADER_H
# define CMD info->command
# define TREAT_OVER info->treatment_over
# define PHASE info->phase
# define ANT_NB info->ant_nb
# define ROOM_NB info->room_nb
# define MAX_PATH info->max_path
# define FIRST info->first
# define PATH info->path
# define START info->start
# define END info->end
# define START_COUNT info->start_count
# define END_COUNT info->end_count
# define INDEX_END info->index_end
# define X_ROOM info->x_room
# define Y_ROOM info->y_room
# define INDEX info->index_room
# define SIZE info->size
# define RECURSIVE info->recursive
# define EX_SOL info->exclusive_sol
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_path
{
	int				*path_index;
	int				flag;
	int				path_len;
	struct s_path	*next;
}					t_path;

typedef struct		s_link
{
	char			*name;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	int				x;
	int				y;
	int				index;
	int				type;
	char			*name;
	t_link			*linked_room;
	int				link_room_count;
	struct s_room	*next;
}					t_room;

typedef struct		s_sol
{
	t_path			*first_path;
	t_path			*last_path;
	int				path_nb;
	int				cycles;
	struct s_sol	*next;
}					t_sol;

typedef struct		s_cycles_info
{
	int				*len_tab;
	int				len_tab_min;
	int				len_tab_max;
}					t_cycles_info;

typedef	struct		s_info
{
	char			*command;
	int				treatment_over;
	int				phase;
	int				ant_nb;
	int				room_nb;
	int				max_path;
	int				index_room;
	int				index_end;
	int				x_room;
	int				y_room;
	int				size;
	t_room			*first;
	t_room			*start;
	t_room			*end;
	t_path			*path;
	int				start_count;
	int				end_count;
	int				treat_over;
	int				recursive;
	int				exclusive_sol;
	t_sol			*sol_first;
	t_sol			*best_sol;
}					t_info;

int					ft_solve(t_info *info, int flag);
t_info				*ft_info_init(void);
t_path				*ft_path_init(t_info *info, t_path *path_lst, int new_index);
int					ft_atoi_lem(const char *str);
int					ft_fill_info(char *line, t_info *info);
int					ft_sharp_treatment(char *line, t_info *info);
int					ft_add_linked_room(t_room *room, char *room_name);
t_room				*ft_room_init(int x, int y, int type, int index);
t_link				*ft_linked_room_init(char *room_name);
void				ft_add_room(char *line, t_info *info, int type);
int					ft_check_p2(char *line, t_info *info);
int					ft_link_rooms(t_info *info, char *room1, char *room2);
void				ft_show_lst_room(t_room *lst);
void				ft_show_info(t_info *info);
void				ft_show_path(t_info *info, t_path *path);
void				ft_free_all(t_info *info);
int					ft_error(void);
#endif
