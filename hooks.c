/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:28:01 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/14 01:56:16 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_hooks.h"

void	free_map(t_map *map)
{
	int	**arr2;
	int	i;

	i = 0;
	arr2 = map->map;
	while (i < map->y)
	{
		free(arr2[i]);
		i++;
	}
	free(arr2);
	free(map);
}

void	close_program(t_vars *vars)
{
	free_map(vars->map);
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		close_program(vars);
	vars->up_to_date = 0;
	return (0);
}
