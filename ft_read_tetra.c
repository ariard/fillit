/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 21:01:03 by ariard            #+#    #+#             */
/*   Updated: 2016/11/13 15:32:10 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int					ft_check_files(char *s, size_t x, size_t y)
{
		if (*s != 10 && *s != 35 && *s != 46)		
			return (1);
//		if (*s == 35 && (*(s + 1) != 35 || *(s + 2) != 35 || *(s + 3) != 35 || 
//			*(s + 4) != 35)) 

//		if (block == 1) 

//		if (x % 5 == 0 && *s != 10)
//			return (0);
		if (y > 131)
			return (1);
//		if (y % 5 == 0 && (*s != 10 || (*(s + 1) != 35 || *(s + 1) != 46)))  
//			return (0);
		y = 0;
		x = 0;
		return (0);	
}

int					ft_check(char	*s)
{
	size_t			x;
	size_t			y;

	x = 1;
	y = 1;
	while (*s)
	{
		if (ft_check_files(s, x, y))
			return (0);
		if ((x == 5 && *s == 10) || (y % 5 == 0 && *s == 10))
		{
			x = 1;
			y++;
			s++;
		}
		else (x++ && *s++);
	}
	return (1);
}

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
		*s++ = buf;
	if (close(fd) == -1)
	{
		ft_putstr("close() failed");
		return ((char *)-1);
	}
	if (ft_check(tmp))
		return (tmp);
	return ("!failed!");
}
