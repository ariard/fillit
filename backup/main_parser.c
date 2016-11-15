# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main_parser                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 14:58:45 by ariard            #+#    #+#              #
/*   Updated: 2016/11/15 15:02:40 by ariard           ###   ########.fr       */
#                                                                              #
# **************************************************************************** #

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char 		*s;
	t_tetra		*tab;

	if (argc > 2)
		ft_putstr("error");
	s = ft_read_tetra(argv[1]);
	printf("fichier passe: \n %s", s);
	return (0);
}
