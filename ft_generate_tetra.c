/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_tetra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:22:13 by ariard            #+#    #+#             */
/*   Updated: 2016/11/14 22:46:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static size_t			ft_count_tetra(char *s)
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

static t_tetra			ft_create_one(char *s, size_t x, size_t y, int i)
{
	t_tetra			tetra;
	size_t			j;

	j = 0;
	while (y % 5 != 0)
	{
		if (*s == 35)
		{
			tetra.pos[i++] = x;
			tetra.pos[i++] = y;
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
	(void)i;
	tetra.print = 'A' + i;
	printf("first block x %d y %d ", tetra.pos[0], tetra.pos[1]);
	return (tetra);
}

t_tetra					*ft_generate_tetra(char *s)
{
	size_t			x;
	size_t			y;
	int				i;
	t_tetra			*tab;

	x = 1;
	y = 1;
	i = 0;
	if (!(tab = (t_tetra *)malloc(sizeof(t_tetra) * ft_count_tetra(s))))
		return (NULL);
	while (*s)
	{
		if (*s == 35 || *s == 46)
		{
			 ft_create_one(s, x, y, i);
			tab++;
			y += 5;
			s += 21;
			i++;
		}
	}
	return (tab);
}
