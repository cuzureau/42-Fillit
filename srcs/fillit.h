/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:12:09 by cuzureau          #+#    #+#             */
/*   Updated: 2017/02/11 12:21:36 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define BUFF_SIZE 550

int				main(int ac, char **av);
int				**ft_create_tab(int j, int i);
int				**ft_filetotab(char *str);
char			**ft_solve(int **coord);
int				ft_width(int **coord, int start);
int				ft_length(int **coord, int start);
void			ft_print(size_t i, char **str);
char			**ft_fill_tab(char **dst);
char			**ft_tab_min(int tetri, int delta);

#endif
