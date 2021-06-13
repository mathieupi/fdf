/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:28:01 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/14 00:47:19 by mmehran          ###   ########.fr       */
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
	if (keycode == KEY_U)
		vars->scale_h += 0.01;
	if (keycode == KEY_J)
		vars->scale_h -= 0.01;
	if (keycode == KEY_W)
		vars->scale += 0.5;
	if (keycode == KEY_S)
		vars->scale -= 0.5;
}

void	do_translation(int keycode, t_vars *vars)
{
	if (keycode == ARROW_RIGHT)
		vars->x_off += 10;
	if (keycode == ARROW_LEFT)
		vars->x_off -= 10;
	if (keycode == ARROW_UP)
		vars->y_off -= 10;
	if (keycode == ARROW_DOWN)
		vars->y_off += 10;
	if (keycode == KEY_T)
		vars->angle_pitch += 1;
	if (keycode == KEY_G)
		vars->angle_pitch -= 1;
	if (keycode == KEY_F)
		vars->angle_yaw += 1;
	if (keycode == KEY_H)
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
