/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_tetra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:30:10 by ariard            #+#    #+#             */
/*   Updated: 2016/11/16 14:56:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

size_t		ft_count_tetra(char *s)
{
	size_t			x;
	size_t			y;
	size_t			i;

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
	return (i + 1);
}

static t_tetra		*ft_create_one(char *s)
{
	t_tetra		*tetra;
	int			y;
	int			x;
	size_t		i;

	y = 1;
	x = 1;
	i = 0;	
	if(!(tetra = (t_tetra *)malloc(sizeof(t_tetra))))
		return (0);
	while (i != 4) 
	{
		if (*s == 35)
		{
			tetra->shape[i].x = x;
			tetra->shape[i].y = y;
			i++;
		}
		if (*s == 10 && (*(s - 1) == 35 || *(s - 1) == 46))
		{
			y++;
			x = 0;
		}
		s++;
		x++;
	}			
	return (tetra);
}

t_tetra		**ft_generate(char *s)
{
	t_tetra	**tab;
	int		first;
	int		i;
	unsigned long nbr;

	nbr = ft_count_tetra(s);
	if (!(tab = (t_tetra **)malloc(sizeof(t_tetra *) * nbr)))
		return (0);
	first = 0;
	i = 0;
	while (*s)
	{
		if ((*(s - 1) == 10 && *(s - 2) == 10) || first == 0)
		{	
			if(!(tab[i] = (t_tetra *)malloc(sizeof(t_tetra))))
				return (0);	
			tab[i] = ft_create_one(s);
			i++;
			first++;
		}
		s++;
	}
//	printf("x1 : %d y1 : %d\n", (*tab[1]).shape[0].x, (*tab[1]).shape[0].y); 
//	printf("x1 : %d y1 : %d\n", (*tab[0]).shape[0].x, (*tab[0]).shape[0].y); 
	return (tab);
}
