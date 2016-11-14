/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:59:32 by ariard            #+#    #+#             */
/*   Updated: 2016/11/14 16:40:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char 		*s;
	t_tetra		*tab;

	if (argc > 2)
		ft_putstr("too many files");
	s = ft_read_tetra(argv[1]);
	tab = ft_generate_tetra(s);
	return (0);
}

//si struct null ou vide ou incomplete
//check si 4 lignes ou moins
//un tetra = 4 lignes 
//si plus de 5 caracteres par ligne
//si caracteres differents de # ou .
//																		si plus de 5 #
//																		si # ne se touche pas
//																		si moins de 4#
//saut de lignes entre chaque structure
//si plus de 26 structures
//
//split verification dans fichier a part
//verification descendante, a partir du premier verifier dans les x suivants si occurence jusqu au 4eme
//un fichier read and clear, un fichier generate structure, un fichier algo, un fichier print
