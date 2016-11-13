# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 16:43:57 by ariard            #+#    #+#              #
#    Updated: 2016/11/13 13:42:05 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Wall -Wextra -Werror
NAME= fillit
SRC= ./main.c ./ft_read_tetra.c
OBJ= ./main.o ./ft_read_tetra.o
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
