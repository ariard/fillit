/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:31:51 by ariard            #+#    #+#             */
/*   Updated: 2016/11/14 16:36:53 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct		s_tetra
{
	int		*pos1;
	int		*pos2;
	int		*pos3;
	int		*pos4;
}					t_tetra;

char				*ft_read_tetra(char *files);

int					ft_check_all(char *s);

t_tetra				*ft_generate_tetra(char	*s);

#endif
