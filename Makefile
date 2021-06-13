# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 06:05:46 by mmehran           #+#    #+#              #
#    Updated: 2021/06/13 14:21:42 by mmehran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

OBJS =

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L ./libs -lft

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

bonus:

.PHONY: all clean fclean re bonus
