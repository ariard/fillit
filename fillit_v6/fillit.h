/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:25:48 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/18 23:07:17 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

/*----------------- INCLUDES -------------------------------------------------*/
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/*----------------- STRUCTURES DE DONNEES ------------------------------------*/
typedef struct		s_vector
{
	int				x;
	int				y;
}					t_vector;

typedef struct		s_tetra
{
	t_vector		shape[4];
	char			print;
	int				ci;
	int				cj;
}					t_tetra;

typedef struct		s_info
{
	int				nb;//nombre de tetriminos
	int				size;//taille minimale du carre
	int				count;//compteur du nombre de pieces placees
	int				i;
	int				j;
}					t_info;
/*----------------- FONCTIONS IMPRESSION -------------------------------------*/
void				ft_putchar(char c);
void				ft_print_usage(void);
void				ft_print_error(void);
void				ft_print_square(char **square, t_info *info);
/*----------------- PARSING --------------------------------------------------*/
char				*ft_read_tetra(char *files);
size_t				ft_count_tetra(char *s);
/*----------------- GENERATION STRUCTURE -------------------------------------*/
t_tetra				**ft_generate(char *s, unsigned long nbr);
/*----------------- VERIFICATIONS DU FICHIER ---------------------------------*/
int					ft_check_all(char *s);
/*----------------- CREATION DU CARRE ----------------------------------------*/
void				ft_min_size(t_info *info);
char				**ft_square(t_info *info);
/*----------------- RESOLUTION -----------------------------------------------*/
int					ft_solve(char **square, t_tetra **tetra, t_info *info);
int					ft_can_i_put(char **square, t_tetra **tetra, t_info *info);
void				ft_put_it(char **square, t_tetra **tetra, t_info *info);
void				ft_erase_it(char **square, t_tetra **tetra, t_info *info);
void				ft_del_square(char **square, t_info *info);

/*----------------- DEFINES --------------------------------------------------*/
# define POS ((*(s + 1) == 35 || *(s + 5) == 35) && block < 3)\
				|| (((*(s + 4) == 35 && *(s - 1) == 35) || (*(s + 3) == 35 &&\
					*(s - 2) == 35)) && (block == 1 || block == 2))\
						|| ((*(s - 1) == 35 || *(s - 5) == 35) && block == 3)

# define CAN_I(a) (square[(info->i) + tetra[info->count]->shape[a].y]\
							[(info->j) + tetra[info->count]->shape[a].x])

# define PUT(a) (square[(info->i) + tetra[info->count]->shape[a].y]\
							[(info->j) + tetra[info->count]->shape[a].x])

# define ERASE(a) (square[tetra[info->count]->shape[a].y]\
							[tetra[info->count]->shape[a].x])
#endif
