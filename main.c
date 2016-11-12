/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:59:32 by ariard            #+#    #+#             */
/*   Updated: 2016/11/13 00:35:53 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**ft_check_tetra(char *files);

int		main(int argc, char **argv)
{
	if (argc > 2)
		ft_putstr("too many files");
	ft_check_tetra(argv[1]);
	return (0);
}


//																		un tetra = 4 lignes 
//																		si plus de 5 caracteres par ligne
//																		si caracteres differents de # ou .
//																		si plus de 5 #
//si # ne se touche pas
//																		si moins de 4#
//																		saut de lignes entre chaque structure
//																		si plus de 26 structures
//
//split verification dans fichier a part
//verification descendante, a partir du premier verifier dans les x suivants si occurence jusqu au 4eme
//un fichier read and clear, un fichier generate structure, un fichier algo, un fichier print
