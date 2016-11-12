/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 21:01:03 by ariard            #+#    #+#             */
/*   Updated: 2016/11/13 00:35:22 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char				*ft_read_tetra(char *files)
{
	int				fd;
	char			buf;
	char			*s;
	char			*tmp;
	size_t			index;

	s = ft_memalloc(527);
	ft_bzero(s, 527);
	index = 0;
	tmp = s;
	fd = open(files, O_RDONLY);
	if (fd == -1)
		return ((char *)-1);
	while (read(fd, &buf, 1))
	{
		*s = buf;
		s++;
	}
	if (close(fd) == -1)
	{
		ft_putstr("close() failed");
		return ((char *)-1);
	}
	return (tmp);
}

int					ft_check_tetra(char	*s)
{
	size_t			x;
	size_t			y;
	int				block;

	x = 0;
	y = 0;
	block = 0;
	while (*s)
	{
		if (*s != 10 || *s != 35 || *s != 46)
			return (0);
		if (*s == 35)
			block++;
		if (*s == 35 && (*(s + 1) != 35 || *(s + 2) != 35 || *(s + 3) != 35 || 
			*(s + 4) != 35 
					

		if (block == 1 

		if (x % 5 == 0 && *s != 10)
			return (0);
		if (y > 130)
			return (0);
		if (y % 5 == 0 && (*s != 10 || (*(s + 1) != 35 || *(s + 1) != 46)))  
			return (0);
		if (y % 5 == 0 && block != 4)
			return (0);
		s++;
	}
	return (1);
}

char				**ft_generate_all_tetra(char *files)
{
	char			*s;
	size_t			x;
	size_t			y;
	t_tetra			*tab;
	t_tetra			tmp;

	if((s = ft_read_tetra(files)) == -1)
		return ((char **)-1);
	x = 0;
	y = 0;
	if (ft_check_tetra(s))
	{
		
	}
	return ((char **)-1);
}
