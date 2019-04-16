/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:22:54 by cuzureau          #+#    #+#             */
/*   Updated: 2017/02/09 17:08:55 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_create_tab(int j, int i)
{
	int		**tab;

	if (!(tab = (int **)malloc(sizeof(int *) * j)))
		return (NULL);
	while (j > 0)
	{
		if (!(tab[j - 1] = (int *)malloc(sizeof(int) * i)))
			return (NULL);
		j--;
	}
	return (tab);
}
