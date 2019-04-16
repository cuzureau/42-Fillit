/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 11:08:00 by cuzureau          #+#    #+#             */
/*   Updated: 2017/02/09 10:58:33 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print(size_t i, char **str)
{
	while (i < ft_strlen(str[i]) - 1)
	{
		ft_putstr(str[i++]);
		ft_putchar('\n');
	}
	ft_putstr(str[i]);
	ft_putchar('\n');
}
