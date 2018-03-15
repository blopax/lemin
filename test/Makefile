# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atourner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 10:28:24 by atourner          #+#    #+#              #
#    Updated: 2018/03/08 13:51:36 by atourner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES_LIB=includes

all: comp_lem cpy_lem error_comp error_test

comp_lem:
	@printf "Compiling your lem-in\n"
	@make -C ../

cpy_lem:
	@cp ../lem-in .
	@printf "Your lem-in is copied\n"

error_comp:
	@printf "Compiling everything needed for testing errors\n"
	@gcc test_error.c -I$(INCLUDES_LIB) libftprintf.a -o error

error_test:
	@printf "Testing error, check error.txt if there is error\n"
	@sh error.sh

clean:
	@rm -rf error lem-in
	@make fclean -C ../
