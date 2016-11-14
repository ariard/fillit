/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_tetra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:22:13 by ariard            #+#    #+#             */
/*   Updated: 2016/11/14 16:42:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static size_t			ft_count_struct(char *s)
{
	size_t				x;
	size_t				y;
	size_t				i;

	i = 1;
	x = 1;
	y = 1;
	while (*s)
	{
		if (y % 5 == 0 && *s == 10)
			i++;
		if ((x == 5 && *s == 10) || (y % 5 == 0 && *s == 10))
		{
			x = 1;
			y++;
			s++;
		}
		else if (*s++)
			x++;
	}
	return (i);
}



t_tetra					*ft_generate_tetra(char *s)
{
		size_t			x;
		size_t			y;
		t_tetra			*tab;

		x = 1;
		y = 1;
		if (!(tab = (t_tetra *)malloc(sizeof(t_tetra) * ft_count_struct(s))))
				return (NULL);
		while (*s == 'A')
		{
//			if (*s == 35)
//				*tab++ = NULL //ft_generate_struct(s, x, y);
			if ((x == 5 && *s == 10) || (y % 5 == 0 && *s == 10))
			{
				x = 1;
				y++;
				s++;
			}
			else if (*s++)
				x++;
		}
		return (0);
}
