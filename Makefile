# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleroy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 20:33:14 by mleroy            #+#    #+#              #
#    Updated: 2016/11/19 19:58:46 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

SRC= main.c\
	 ft_print_usage.c\
	 ft_read_tetra.c\
	 ft_check_all.c\
	 ft_generate_tetra.c\
	 ft_first_grid.c\
	 ft_solve.c\

OUT= main.o\
	 ft_solve.o\
	 ft_print_usage.o\
	 ft_read_tetra.o\
	 ft_check_all.o\
	 ft_generate_tetra.o\
	 ft_first_grid.o\

HEADER= fillit.h libft.a

FLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@ gcc -c $(FLAGS) $(SRC)
	@ gcc -o $(NAME) -I $(HEADER) $(OUT) $(FLAGS)

clean:
	@ rm -f $(OUT)

fclean: clean
	@ rm -f $(NAME)

re: fclean all
