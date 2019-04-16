/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:40:35 by cuzureau          #+#    #+#             */
/*   Updated: 2017/02/10 16:23:39 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_width(int **coord, int start)
{
	int		max;
	int		min;
	int		i;

	max = 0;
	min = 4;
	i = 0;
	while (i < 4)
	{
		(coord[0][start] < min) ? min = coord[0][start] : 0;
		(coord[0][start] > max) ? max = coord[0][start] : 0;
		start++;
		i++;
	}
	return (max - min + 1);
}
