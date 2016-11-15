/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_tetra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:22:13 by ariard            #+#    #+#             */
/*   Updated: 2016/11/15 22:47:23 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*static size_t			ft_count_tetra(char *s)
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
}*/

t_tetra			*ft_create_one(char *s, size_t x, size_t y, int i)
{
	t_tetra			*tetra;
	int				j;

	j = i;
	tetra = (t_tetra *)malloc(sizeof(t_tetra));
	if (!tetra)
		return (NULL);
	while (y % 5 != 0)
	{
		if (*s == 35)
		{
			tetra->shape[i].x = x;
			tetra->shape[i].y = y;
			i++;
		}
		if ((x == 5 && *s == 10) || (y % 5 == 0 && *s == 10))
		{
			x = 1;
			y++;
			s++;
		}
		else if (*s++)
			x++;
	}
	tetra->print = 'A' + j;	
	return (tetra);
}

/*t_tetra					**ft_generate_tetra(char *s)
{
	size_t			x;
	size_t			y;
	int				i;
	int test;
	t_tetra			**tab;

	x = 1;
	y = 1;
	i = 0;
	test = 0;
	if (!(tab = (t_tetra **)malloc(sizeof(t_tetra *) * ft_count_tetra(s))))
		return (NULL);
	while (*s)
	{	
		if ((*s == 35 || *s == 46)) 
		{
			ft_create_one(s, x, y, i);
			tab++;
			y += 5;
			s += 21;
			i++;
			test++;
		}
		s++;
	}
	return (tab);
}*/
