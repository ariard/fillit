/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:46:09 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/18 21:58:39 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	ft_del_square(char **square, t_info *info)
{
	int		i;

	i = 0;
	while (i < info->size)
	{
		free(square[i]);
		square[i] = NULL;
		i++;
	}
	free(square);
	square = NULL;
}
