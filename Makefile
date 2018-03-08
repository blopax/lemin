NAME = fdf

#compiler
CC = clang
CFLAGS = -Werror -Wall -Wextra

#flags for preprocessor
CPPFLAGS = -Iincludes/ -Ilibft/
LFLAGS = -Llibft -lft -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit
LFLAGS_DEBUG = -Llibft -lft-debug -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

#deps
DEPENDENCIES = Includes/ft_fdf.h Makefile

#libs
LIB_PATH = libft/
LIB_NAME = libft.a
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

#srcs
SRC_PATH =
SRC = ft_utilities.c ft_get_table.c main.c\
		ft_mlx_tab_treat.c ft_draw_lines.c ft_transfo.c ft_scale.c\
		ft_rotation_map.c ft_manipulate_data.c ft_mlx_tab_treat_utilities.c\
		ft_draw_utilities.c

#obj
OBJ_PATH = obj/
OBJ_NAME = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Debug variables
DBG_CFLAGS = -g
DBG_LIB_NAME = libft-debug.a
DBG_NAME = $(NAME)-debug
DBG_PATH = debug/
DBG_OBJ = $(addprefix $(DBG_PATH), $(OBJ_NAME))
DBG_LIB = $(addprefix $(LIB_PATH), $(LIB_PATH)-debug.a)

# Colours
CYAN = \x1b[36m
GREEN = \x1b[32m
YELLOW = \x1b[33m
END_COLOUR = \x1b[0m

#disable implicit rules
.SUFFIXES:
.PHONY: clean fclean all re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) -o $@
	@echo "$(GREEN) Binary compilation succesfull$(END_COLOUR)"

$(OBJ_PATH)%.o: %.c $(DEPENDENCIES) $(LIB)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIB): libft/*.c libft/libft.h libft/Makefile
	@echo "$(CYAN) Compiling library $(END_COLOUR)"
	@$(MAKE) -C libft/

debug: $(DBG_OBJ)
	$(CC) $(LFLAGS_DEBUG) $(DBG_OBJ) $(DBG_CFLAGS) -o $(DBG_NAME)
	@echo "$(GREEN) Binary compilation succesfull$(END_COLOUR)"

$(DBG_PATH)%.o: %.c $(DEPENDENCIES) $(DBG_LIB)
	@mkdir $(DBG_PATH) 2> /dev/null || true
	$(CC) $(DBG_CFLAGS) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(DBG_LIB): libft/*.c libft/libft.h libft/Makefile
	@echo "$(CYAN) Compiling library $(END_COLOUR)"
	@$(MAKE) -C libft/ debug

valgrind: debug
	valgrind --leak-check=full ./$(DBG_NAME)

clean:
	@echo "$(YELLOW) Removing objects $(END_COLOUR)"
	@$(MAKE) -C libft/ clean
	@$(RM) $(OBJ)
	@$(RM) $(DBG_OBJ)
	@$(RM) -R $(OBJ_PATH) 2> /dev/null || true
	@$(RM) -R $(DBG_PATH) 2> /dev/null || true

fclean: clean
	@echo "$(YELLOW) Removing binary $(END_COLOUR)"
	@$(MAKE) -C libft/ fclean
	@$(RM) $(NAME)
	@$(RM) $(DBG_NAME)

re:
	@echo "Recompiling"
	@$(MAKE) fclean
	@$(MAKE) all
