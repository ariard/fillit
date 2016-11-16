/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:31:51 by ariard            #+#    #+#             */
/*   Updated: 2016/11/16 14:50:24 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

# define POS ((*(s + 1) == 35 || *(s + 5) == 35) && block < 3)\
				|| (((*(s + 4) == 35 && *(s - 1) == 35) || (*(s + 3) == 35 &&\
					*(s - 2) == 35)) && (block == 1 || block == 2))\
						|| ((*(s - 1) == 35 || *(s - 5) == 35) && block == 3)

typedef struct		s_vector
{
	int				x;
	int				y;
}					t_vector;

typedef struct		s_tetra
{
	t_vector		shape[4];
	char			print;	
}					t_tetra;

char				*ft_read_tetra(char *files);

int					ft_check_all(char *s);

t_tetra				**ft_generate(char	*s);

#endif
