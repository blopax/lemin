# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atourner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 10:28:24 by atourner          #+#    #+#              #
#    Updated: 2018/03/19 16:12:04 by atourner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES_LIB=includes

all: comp_lem error_comp normal_comp validity_comp error_test normal_test validity_test

comp_lem:
	@printf "Compiling your lem-in\n"
	@make -C ../

error_comp:
	@printf "Compiling everything needed for testing errors\n"
	@gcc test_error.c -I$(INCLUDES_LIB) lib/libftprintf.a -o error

validity_comp:
	@printf "Compiling everything needed for testing validity\n"
	@gcc test_validity/check_double.c test_validity/create_link.c\
		test_validity/ft_check_room.c test_validity/ft_get_anthill.c\
		test_validity/lem_in.c test_validity/mem_struct_room.c\
		test_validity/mem_struct_room2.c test_validity/parser.c\
		test_validity/parser2.c test_validity/possible_move.c -I$(INCLUDES_LIB)\
		lib/libftprintf.a -o validity

normal_comp:
	@printf "Compiling everything needed for testing normal\n"
	@gcc test_normal.c -I$(INCLUDES_LIB) lib/libftprintf.a -o normal

error_test:
	@printf "Testing error, check error.txt if there is error\n"
	@sh scripts/error.sh

validity_test :
	@printf "Testing validity, check validity.txt if there is error\n"
	@sh scripts/validity.sh

normal_test:
	@echo "\nNormal launch\nif green, optimal is reach\nif orange, optimal isn't reach\nif red, reponse if false\nCheck normal.txt\nIt only check the number of moves, not if it is correct ! Check the result yourself!"
	@sh scripts/normal.sh

clean:
	@rm -rf leaks error lem-in normal normal.txt error.txt ant validity
	@make fclean -C ../
