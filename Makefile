# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 06:05:46 by mmehran           #+#    #+#              #
#    Updated: 2021/06/14 00:58:51 by mmehran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBS = -L ./libft -lft -L minilibx/ -lmlx -lm

OBJS = main.o hooks.o transform.o fdf.o draw.o

$(NAME): $(OBJS)
	make -C ./minilibx
	cp ./minilibx/libmlx.dylib ./
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
