NAME = lem-in

#compiler
CC = clang
CFLAGS = -Werror -Wall -Wextra

#flags for preprocessor
CPPFLAGS = -Iincludes/ -Ilibft/
LFLAGS = -Llibft -lft
LFLAGS_DEBUG = -Llibft -lft-debug

#deps
DEPENDENCIES = includes/header.h Makefile

#libs
LIB_PATH = libft/
LIB_NAME = libft.a
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

#srcs
SRC_PATH =srcs/
SRC_NAME = ft_fill_info.c ft_fill_info_utls.c ft_init_struct.c ft_lem_in.c\
		   ft_create_room.c ft_safe_free_lst.c ft_atoi_lem_in.c\
		   ft_solve.c ft_path_combi.c ft_cycles_treatment.c\
		   ft_solve_utilities.c ft_path_combi_utilities.c ft_move_ants.c\
		   ft_move_ants_utilities.c ft_display.c ft_create_room_utilities.c
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

#obj
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
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

$(OBJ_PATH)%.o: $(SRC_PATH)/%.c $(DEPENDENCIES) $(LIB)
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
