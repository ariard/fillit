/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_tetra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:36:13 by ariard            #+#    #+#             */
/*   Updated: 2016/11/13 13:37:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			**ft_generate_all_tetra(char *files)
{
	char		*s;
	size_t		x;
	size_t		y;
	t_tetra		*tab;
	t_tetra		tmp;

	x = 0;
	y = 0;
