/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenght.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:15:04 by cuzureau          #+#    #+#             */
/*   Updated: 2017/02/10 16:21:49 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_length(int **coord, int start)
{
	int		max;
	int		min;
	int		i;

	max = 0;
	min = 4;
	i = 0;
	while (i < 4)
	{
		(coord[1][start] < min) ? min = coord[1][start] : 0;
		(coord[1][start] > max) ? max = coord[1][start] : 0;
		start++;
		i++;
	}
	return (max - min + 1);
}
