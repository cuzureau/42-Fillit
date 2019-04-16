/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:40:49 by cuzureau          #+#    #+#             */
/*   Updated: 2017/02/11 13:09:02 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_remove_piece(char **dst, int **coord, int start, int *t)
{
	dst[coord[0][start] + t[0]][coord[1][start] + t[1]] = '.';
	dst[coord[0][start + 1] + t[0]][coord[1][start + 1] + t[1]] = '.';
	dst[coord[0][start + 2] + t[0]][coord[1][start + 2] + t[1]] = '.';
	dst[coord[0][start + 3] + t[0]][coord[1][start + 3] + t[1]] = '.';
	return (dst);
}

static int	ft_place(char **dst, int **coord, int start, int *t)
{
	if (dst[coord[0][start] + t[0]][coord[1][start] + t[1]] == '.' &&
		dst[coord[0][start + 1] + t[0]][coord[1][start + 1] + t[1]] == '.' &&
		dst[coord[0][start + 2] + t[0]][coord[1][start + 2] + t[1]] == '.' &&
		dst[coord[0][start + 3] + t[0]][coord[1][start + 3] + t[1]] == '.')
		return (1);
	return (0);
}

static char	**ft_put_pieces(int az, int s, char **dst, int **c)
{
	int		t[2];

	t[0] = -1;
	if (c[0][s] == 99)
		return (dst);
	while (dst && ++t[0] <= ((int)ft_strlen(dst[0]) - (ft_width(c, s))))
	{
		t[1] = -1;
		while (dst && ++t[1] <= ((int)ft_strlen(dst[0]) - (ft_length(c, s))))
		{
			if (ft_place(dst, c, s, t) == 1)
			{
				dst[c[0][s] + t[0]][c[1][s] + t[1]] = az;
				dst[c[0][s + 1] + t[0]][c[1][s + 1] + t[1]] = az;
				dst[c[0][s + 2] + t[0]][c[1][s + 2] + t[1]] = az;
				dst[c[0][s + 3] + t[0]][c[1][s + 3] + t[1]] = az;
				if (!ft_put_pieces(az + 1, s + 4, dst, c))
					ft_remove_piece(dst, c, s, t);
				else
					return (dst);
			}
		}
	}
	return (0);
}

static int	**ft_put_up_left(int j, int i, int newline, int **coord)
{
	int		min;

	min = 3;
	while (j < 2)
	{
		while (coord[j][i] != 99)
		{
			(coord[j][i] < min) ? min = coord[j][i] : 0;
			newline++;
			i++;
			if (newline % 5 == 0)
			{
				coord[j][i - 1] = coord[j][i - 1] - min;
				coord[j][i - 2] = coord[j][i - 2] - min;
				coord[j][i - 3] = coord[j][i - 3] - min;
				coord[j][i - 4] = coord[j][i - 4] - min;
				newline++;
				min = 3;
			}
		}
		i = 1;
		newline = 1;
		j++;
	}
	return (coord);
}

char		**ft_solve(int **coord)
{
	char	**dst;
	int		i;

	i = 0;
	dst = ft_tab_min(coord[0][0], i);
	coord = ft_put_up_left(0, 1, 1, coord);
	while (!(dst = ft_put_pieces(65, 1, dst, coord)))
		dst = ft_tab_min(coord[0][0], ++i);
	return (dst);
}
