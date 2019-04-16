# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/09 14:08:28 by cuzureau          #+#    #+#              #
#    Updated: 2017/02/11 13:10:11 by cuzureau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

SRC		=	./srcs/main.c \
			./srcs/ft_create_tab.c \
			./srcs/ft_filetotab.c \
			./srcs/ft_fill_tab.c \
			./srcs/ft_lenght.c \
			./srcs/ft_print.c \
			./srcs/ft_solve.c \
			./srcs/ft_width.c \
			./srcs/ft_tab_min.c

FLAGS	=	-Wall -Wextra -Werror

INC		=	./srcs/fillit.h

LINC	=	./libft

all: $(NAME)

$(NAME):
	make -C $(LINC)
	gcc $(FLAGS) -o $(NAME) $(LINC)/libft.a $(SRC) -I $(INC) -I $(LINC)/libft.h

clean:
	make clean -C $(LINC)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LINC)

re: clean fclean all

.PHONY: all clean fclean re
