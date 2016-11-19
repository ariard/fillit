/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:21:40 by ariard            #+#    #+#             */
/*   Updated: 2016/11/19 19:56:32 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t				ft_count_tetra(char *s)
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

void				ft_del_square(char **square, t_info *info)
{
	int				i;

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

char				*ft_read_tetra(char *files)
{
	int				fd;
	char			buf;
	char			*s;
	char			*tmp;
	size_t			index;

	s = ft_memalloc(545);
	ft_bzero(s, 545);
	index = 0;
	tmp = s;
	fd = open(files, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (read(fd, &buf, 1))
		*s++ = buf;
	if (close(fd) == -1)
		return (NULL);
	if (ft_strlen(tmp) == 0)
		return (NULL);
	if (ft_check_all(tmp))
		return (NULL);
	return (tmp);
}
