/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:21:31 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/13 20:18:48 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_draw.h"
#include "fdf_hooks.h"

int	render_next_frame(t_vars *vars)
{
	if (vars->sec++ < 1000)
		return (0);
	vars->sec = 0;
	if (vars->up_to_date)
		return (0);
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, vars->img.w, vars->img.h);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	draw_map(vars, vars->map);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	vars->up_to_date = 1;
	return (0);
}

void	start(t_map *map)
{
	t_vars	vars;

	vars.up_to_date = 0;
	vars.map = map;
	vars.img.w = 1280;
	vars.img.h = 720;
	vars.sec = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.img.w, vars.img.h, "fdf");
	vars.img.img = mlx_new_image(vars.mlx, vars.img.w, vars.img.h);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	vars.scale_h = 0.1;
	vars.scale = (vars.img.w + vars.img.h) / (map->x + map->y + 1) / 1.5;
	vars.x_off = vars.img.w / 3;
	vars.y_off = 0;
	vars.angle_pitch = 45;
	vars.angle_yaw = 35;
	mlx_hook(vars.win, 2, 1, key_hook, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
}
