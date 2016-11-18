/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:25:32 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/18 23:21:28 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		main(int argc, char **argv)
{
	char		*s;
	t_info		info;
	t_tetra		**tetra;
	char		**square;

	info.count = 0;
	if (argc != 2)
	{
		ft_print_usage();
		return (1);
	}
	s = ft_read_tetra(argv[1]);
	info.nb = ft_count_tetra(s) - 1;
	printf("nombre de tetra = %i\n", info.nb);
	if ((tetra = ft_generate(s, info.nb + 1)) == NULL)
		return (1);
	printf("%i structure(s) cree(s)\n", info.nb);
	ft_min_size(&info);
	printf("taille du carre = %i x %i\n", info.size, info.size);
	square = ft_square(&info);
	if (square == NULL)
		return (1);
	ft_print_square(square, &info);
	while (ft_solve(square, tetra, &info) != 1)
	{
		ft_del_square(square, &info);
		info.size += 1;
		square = ft_square(&info);
		printf("augmentation du carre\n");
	}
	printf("resolution terminee\n");
	return (0);
}
