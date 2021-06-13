/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:21:38 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/14 00:01:57 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <fcntl.h>

int	parse_map_info(int fd, t_map *map)
{
	char	*line;
	int		x;
	char	**point;
	char	**p;
	int		code;

	code = 0;
	while (get_next_line(fd, &line) == 1)
	{
		x = 0;
		point = ft_split(line, ' ');
		p = point;
		while (*p && ++x)
			free(*(p++));
		free(line);
		free(point);
		if (map->x != 0 && x != map->x)
			code = 1;
		map->x = x;
		map->y++;
	}
	return (code);
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
	int		code;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error map doesn't exist :/\n", 4);
		exit(0);
	}
	map = malloc(sizeof(t_map));
	map->x = 0;
	map->y = 0;
	code = parse_map_info(fd, map);
	close(fd);
	if (code)
	{
		write(2, "Error map isn't a rectangle :/\n", 28);
		free(map);
		exit(0);
	}
	fd = open(file, O_RDONLY);
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

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
	{
		write(2, "Bad args :/, try something like: './fdf 42.fdf'\n", 48);
		return (0);
	}
	map = get_map(av[1]);
	start(map);
}
