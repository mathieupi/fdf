# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 06:05:46 by mmehran           #+#    #+#              #
#    Updated: 2021/06/14 01:49:04 by mmehran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBS = -L ./libft -lft -L minilibx/ -lmlx -lm

OBJS = main.o hooks.o transform.o fdf.o draw.o
OBJS_BONUS = main.o hooks_bonus.o transform.o fdf.o draw.o

ifdef WITH_BONUS
OBJS = $(OBJS_BONUS)
endif

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
	make -C ./minilibx clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:
	make -C ./libft fclean
	make -C ./minilibx fclean
	$(RM) $(NAME) libmlx.dylib
	$(RM) $(OBJS) $(OBJS_BONUS)

re: clean all

bonus:
	$(MAKE) WITH_BONUS=1 all

.PHONY: all clean fclean re bonus
