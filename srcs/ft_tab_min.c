/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:36:54 by cuzureau          #+#    #+#             */
/*   Updated: 2017/02/11 11:44:51 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_tab_min(int tetri, int delta)
{
	char	**dst;
	int		odd;
	int		i;
	int		j;

	i = delta;
	odd = 1;
	tetri = tetri * 4;
	while (tetri > 0)
	{
		tetri = tetri - odd;
		odd = odd + 2;
		i++;
	}
	j = i;
	if (!(dst = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	while (j > 0)
	{
		dst[j - 1] = ft_strnew((size_t)i);
		ft_memset(dst[j - 1], '.', i);
		j--;
	}
	return (dst);
}
