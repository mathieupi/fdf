/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:21:38 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/13 15:42:26 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "fdf.h"
#include <fcntl.h>

void	parse_map_info(int fd, t_map *map)
{
	char	*line;
	int		x;
	char	**point;
	char	**p;

	map->x = 0;
	map->y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		x = 0;
		point = ft_split(line, ' ');
		p = point;
		while (*p)
		{
			free(*p);
			p++;
			x++;
		}
		map->x = x;
		map->y++;
		free(line);
		free(point);
	}
}

void	parse_map(int fd, t_map *map)
{
	char	*line;
	int		**arr2;
	char	**point;
	int		*arr;

	arr2 = malloc(sizeof(int **) * map->y);
	while (get_next_line(fd, &line) == 1)
	{
		point = ft_split(line, ' ');
		arr = malloc(sizeof(int *) * map->x);
		while (*point)
		{
			*arr = ft_atoi(*point);
			free(*point);
			point++;
			arr++;
		}
		free(line);
		free(point - map->x);
		*arr2 = arr - map->x;
		arr2++;
	}
	map->map = arr2 - map->y;
}

t_map	*get_map(char *file)
{
	int		fd;
	t_map	*map;

	fd = open(file, 0);
	map = malloc(sizeof(t_map));
	parse_map_info(fd, map);
	close(fd);
	//printf("%d %d\n", map->x, map->y);
	fd = open(file, 0);
	parse_map(fd, map);
	close(fd);
	return (map);
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			ft_putnbr_fd(map->map[i][j], 1);
			j++;
		}
		ft_putstr_fd("\n", 1);
		i++;
	}
}

/*void free_map(t_map *map)
{
	int **arr2 = map->map;
	int i = 0;
	while (i < map->y)
	{
		free(arr2[i]);
		i++;
	}
	free(arr2);
	free(map);
} */

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		return (0);
	map = get_map(av[1]);
	//print_map(map);
	start(map);
}
