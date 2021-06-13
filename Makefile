# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 06:05:46 by mmehran           #+#    #+#              #
#    Updated: 2021/06/13 21:33:28 by mmehran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBS = -L ./libft -lft -L ./minilibx-linux/ -lmlx -lm -lbsd -lX11 -lXext

OBJS = main.o hooks.o transform.o fdf.o draw.o

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

clean:
	make -C ./libft clean
	$(RM) $(OBJS)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re: clean all

bonus:

.PHONY: all clean fclean re bonus
