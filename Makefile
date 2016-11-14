# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 16:43:57 by ariard            #+#    #+#              #
#    Updated: 2016/11/14 16:38:08 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Wall -Wextra -Werror
NAME= fillit
SRC= ./main.c ./ft_generate_tetra.c ./ft_check_all.c ./ft_read_tetra.c
OBJ= ./main.o ./ft_generate_tetra.o ./ft_check_all.o ./ft_read_tetra.o
HEA= fillit.h libft.a

all : $(NAME)

$(NAME):
	@ $(CC) $(CFLAGS) -c $(SRC) 
	@ $(CC) $(CFLAGS) $(OBJ) -I $(HEA) -o $(NAME)

clean:
	@ /bin/rm -f $(OBJ)

fclean: clean 
	@ rm -f $(NAME)

re: fclean clean all
