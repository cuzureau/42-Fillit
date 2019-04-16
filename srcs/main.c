/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:12:04 by cuzureau          #+#    #+#             */
/*   Updated: 2017/02/14 13:23:30 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		**coord;

	coord = ft_create_tab(2, 106);
	if (ac != 2)
		ft_putstr("usage: ./fillit file\n");
	else
	{
		if (!(coord = ft_filetotab(av[1])) || coord[0][0] == 0)
			ft_putstr("error\n");
		else
			ft_print(0, ft_solve(coord));
	}
	return (0);
}
