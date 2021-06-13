/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:28:01 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/13 23:44:16 by mmehran          ###   ########.fr       */
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

void	do_scaling(int keycode, t_vars *vars)
{
	if (keycode == 'u')
		vars->scale_h += 0.01;
	if (keycode == 'j')
		vars->scale_h -= 0.01;
	if (keycode == 'w')
		vars->scale += 0.5;
	if (keycode == 's')
		vars->scale -= 0.5;
}

void	do_translation(int keycode, t_vars *vars)
{
	if (keycode == 65363)
		vars->x_off += 10;
	if (keycode == 65361)
		vars->x_off -= 10;
	if (keycode == 65362)
		vars->y_off -= 10;
	if (keycode == 65364)
		vars->y_off += 10;
	if (keycode == 't')
		vars->angle_pitch += 1;
	if (keycode == 'g')
		vars->angle_pitch -= 1;
	if (keycode == 'f')
		vars->angle_yaw += 1;
	if (keycode == 'h')
		vars->angle_yaw -= 1;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_program(vars);
	do_translation(keycode, vars);
	do_scaling(keycode, vars);
	vars->up_to_date = 0;
	return (0);
}
