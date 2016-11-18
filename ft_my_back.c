/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 22:07:07 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/18 22:19:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

void	ft_erase_it(char **square, t_tetra **tetra, t_info *info)
{
	int		i;

	i = 0;
	info->i = tetra[info->count]->ci;
	info->j = tetra[info->count]->cj;
	square[info->i][info->j] = '.';
	i++;
	while (info->j != info->size && info->i != info->size)
	{
		if (square[info->i][info->j] == tetra[info->count]->print)
		{
			square[info->i][info->j] = '.';
			i++;
		}
		if (info->j < info->size)
			info->j = info->j + 1;
		if (info->j == info->size - 1)
		{
			info->j = 0;
			info->i = info->i + 1;
		} 
	} 
	info->i = 0;
	info->j = 0;	
}

void	ft_put_it(char **square, t_tetra **tetra, t_info *info)
{
	PUT(0) = tetra[info->count]->print;
	PUT(1) = tetra[info->count]->print;
	PUT(2) = tetra[info->count]->print;
	PUT(3) = tetra[info->count]->print;
}

void	ft_reset_decallage(t_info *info)
{
	info->i = 0;
	info->j = 0;
}

int		ft_can_i_put(char **square, t_tetra **tetra, t_info *info)
{
	if (((tetra[info->count]->shape[1].x < 0)
		|| (tetra[info->count]->shape[2].x < 0)
			||(tetra[info->count]->shape[3].x < 0)) && info->j == 0)
		return (0);
	if (((0 > (info->j + tetra[info->count]->shape[0].x)) || (info->size - 1 < (info->j + tetra[info->count]->shape[0].x))) || 
			((0 > (info->j + tetra[info->count]->shape[1].x)) || (info->size - 1 < (info->j + tetra[info->count]->shape[1].x))) || 
			((0 > (info->j + tetra[info->count]->shape[2].x)) || (info->size - 1 < (info->j + tetra[info->count]->shape[2].x))) || 
			((0 > (info->j + tetra[info->count]->shape[3].x)) || (info->size - 1 < (info->j + tetra[info->count]->shape[3].x))) || 
			 ((0 > (info->i + tetra[info->count]->shape[0].y)) || (info->size - 1 < (info->i + tetra[info->count]->shape[0].y))) ||
			((0 > (info->i + tetra[info->count]->shape[1].y)) || (info->size - 1 < (info->i + tetra[info->count]->shape[1].y))) ||
			((0 > (info->i + tetra[info->count]->shape[2].y)) || (info->size - 1 < (info->i + tetra[info->count]->shape[2].y))) ||
			((0 > (info->i + tetra[info->count]->shape[3].y)) || (info->size - 1 < (info->i + tetra[info->count]->shape[3].y))))
	{
		printf("coucou\n");	
		return (0);
	} 
	if ((CAN_I(0) == '.') && (CAN_I(1) == '.')
			&& (CAN_I(2) == '.') && (CAN_I(3) == '.'))
	{
		return (1);
	}
	else
		return (0);
}

int		ft_solve(char **square, t_tetra **tetra, t_info *info)
{
	info->i = 0;
	info->j = 0;
	info->count = 0;
	while (info->count < info->nb)
	{
		printf("x : %d\n", info->j);
		printf("y : %d\n", info->i);
		if (ft_can_i_put(square, tetra, info) == 1)
		{
			ft_putstr("placement\n");
			ft_put_it(square, tetra, info);
			tetra[info->count]->ci = (info->i) + tetra[info->count]->shape[0].y;
			tetra[info->count]->cj = (info->j) + tetra[info->count]->shape[0].x;
			ft_reset_decallage(info);
			ft_print_square(square, info);
		//	ft_erase_it(square, tetra, info);
		//	ft_putchar(10);
		//	ft_print_square(square, info);
			info->count += 1;
			ft_putstr("fin de placement");
			ft_putchar(10);
		}
		else if (info->j < info->size - 1)
		{
			printf("\nx + 1");
			info->j += 1;
		}
		else if ((info->j == info->size - 1) && (info->i != info->size - 1))
		{
			printf("\ny + 1");
			info->j = 0;
			info->i += 1;
		}
		else if ((info->j == info->size - 1) && (info->i == info->size - 1))
		{
			printf("\nerase");
		/*	info->count -= 1;
			if (info->count < 0)
				return (0);
		//	ft_erase_it(square, tetra, info);
			if (tetra[info->count]->cj < info->size)
			{
				tetra[info->count]->cj += 1;
			}
			else if (((tetra[info->count]->cj) % (info->size) == 0)
						&& ((tetra[info->count]->ci < (info->size - 1))))
			{
				tetra[info->count]->cj = 0;
				tetra[info->count]->ci += 1;
			}
			else if (tetra[info->count]->cj == (info->size - 1)
					&& (tetra[info->count]->ci == (info->size - 1)))
			{
				tetra[info->count]->cj = 0;
				tetra[info->count]->ci += 1;
			}
			info->j = tetra[info->count]->cj;
			info->i = tetra[info->count]->ci; */
		}
		printf("je suis la\n");
	

			//effacement du tetra d'avant'
/*
			if (CAN_I_PUT_IT)
			{
				PUT_IT
				RESET_DECALLAGE
				CX = X //si structure place on enregistre les coordonnes de son block zero place sur la map, pouyr pouvoir le decaler si on revient en arriere
				CY = Y
				PIECE PLACE++
			}
			else if (x  != x max)
				x++
			else if (x == x max && y != max)
				x = 0;
				y++;
			else if (x = xmax && y == ymax)
			{
				PIECE PLACE--
				IF (PIECE PLACE == -1)
					generate_map bigger
				ERASE_PIECE
				IF (CX != XMAX)
					CX = CX + 1
				ELSE IF (CX == XMAX)
					CX = 0
					CY = CY + 1
				X = CX;
				Y = CY;
			}
			}
		}*/	
	}
	return (1);
}
