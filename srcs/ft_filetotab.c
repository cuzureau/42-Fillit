/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetotab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:46:32 by cuzureau          #+#    #+#             */
/*   Updated: 2017/02/11 11:20:31 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	ft_validmap(int dot, int new, int hash, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		dot = dot + (str[i] == '.' ? 1 : 0);
		hash = hash + (str[i] == '#' ? 1 : 0);
		new = new + (str[i] == '\n' ? 1 : 0);
		if (i % 21 == 0 && new % 5 != 0)
			return (0);
		i++;
	}
	i++;
	if (i % 21 != 0)
		return (0);
	i = i / 21;
	if (dot != 12 * i || hash != 4 * i || new != (4 * i + i - 1))
		return (0);
	return (i);
}

static int	ft_link(int **coord, int k, int l, int m)
{
	int		i;
	int		j;
	int		link;

	i = k - 1;
	j = k;
	link = 0;
	while (j > (k - 4))
	{
		while (i > (k - 4))
		{
			if (coord[l][j] == coord[l][i])
			{
				if (coord[m][j] == (coord[m][i] - 1) || coord[m][j] == \
						(coord[m][i] + 1))
					link++;
			}
			i--;
		}
		j--;
		if (i == (k - 4))
			i = j - 1;
	}
	return (link);
}

static int	**ft_validtetri(int i, int j, int k, char **tab)
{
	int		**coord;
	int		newline;

	newline = 0;
	coord = ft_create_tab(2, 105);
	while (tab[j])
	{
		while (tab[j][i])
		{
			if (tab[j][i] == '#')
			{
				coord[0][k] = (j + newline);
				coord[1][k] = i;
				(k % 4 == 0) ? newline++ : 0;
				if ((k % 4 == 0) && \
					((ft_link(coord, k, 0, 1) + ft_link(coord, k, 1, 0)) < 3))
					coord[0][0] = 99;
				k++;
			}
			i++;
		}
		j++;
		i = 0;
	}
	return (coord);
}

static int	**ft_rect(int **coord)
{
	int		i;
	int		j;
	int		newline;

	i = 1;
	j = 0;
	newline = 1;
	while (i < 106)
	{
		if (newline % 5 == 0)
		{
			j = j + 5;
			newline++;
		}
		coord[0][i] = coord[0][i] - j;
		if (coord[0][i] < 0)
		{
			coord[0][i] = 99;
			coord[1][i] = 99;
			break ;
		}
		i++;
		newline++;
	}
	return (coord);
}

int			**ft_filetotab(char *src)
{
	int		fd;
	int		ret;
	char	*buf;
	int		**coord;

	if (!(buf = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (NULL);
	coord = ft_create_tab(2, 105);
	fd = open(src, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (ret > 546 || ret == -1)
		return (NULL);
	coord = ft_validtetri(0, 0, 1, ft_strsplit(buf, '\n'));
	if (coord[0][0] == 99)
	{
		coord[0][0] = 0;
		return (coord);
	}
	coord[0][0] = ft_validmap(0, 0, 0, buf);
	return (ft_rect(coord));
}
