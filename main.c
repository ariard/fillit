/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:59:32 by ariard            #+#    #+#             */
/*   Updated: 2016/11/14 20:57:23 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char		*s;
	t_tetra		*tab;

	if (argc > 2)
		ft_putstr("error");
	s = ft_read_tetra(argv[1]);	
	tab = ft_generate_tetra(s);
	return (0);
}
