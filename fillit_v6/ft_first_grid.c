/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:17:19 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/18 19:45:36 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "fillit.h"
#include <stdio.h>

void	ft_min_size(t_info *info)
{
	int			i;

	i = 0;
	while ((i * i) < (info->nb * 4))
		i++;
	info->size = i;
}

char	**ft_square(t_info *info)
{
	int		i;
	char	**square;

	i = 0;
	if ((square = (char **)malloc(sizeof(char *) * info->size)) == NULL)
		return (NULL);
	while (i < info->size)
	{
		if ((square[i] = ft_memalloc(info->size)) == NULL)
			return(NULL);
		ft_memset(square[i], 46, info->size);
		square[i][info->size] = '\0';
		i++;
	}
	return (square);
}

void	ft_print_square(char **square, t_info *info)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < info->size)
	{
		ft_putstr(square[i]);
		ft_putchar('\n');
		i++;
	}
}
