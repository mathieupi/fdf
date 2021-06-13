/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:48:17 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/11 23:28:03 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_transform.h"

t_coord	rotate_y(t_coord coord, double rad)
{
	t_coord	new_coord;

	new_coord.x = coord.x * cos(rad) - coord.y * sin(rad);
	new_coord.z = coord.z;
	new_coord.y = coord.x * sin(rad) + coord.y * cos(rad);
	return (new_coord);
}

t_point	transform(t_coord coord, t_vars *vars)
{
	double	pitch;
	double	yaw;
	t_point	new_pos;

	yaw = vars->angle_yaw / 180.0 * M_PI;
	pitch = vars->angle_pitch / 180.0 * M_PI;
	coord = rotate_y(coord, yaw);
	coord.y = coord.z * -sin(pitch) * vars->scale_h + coord.y * cos(pitch);
	new_pos.x = coord.x;
	new_pos.y = coord.y;
	new_pos.x *= vars->scale;
	new_pos.y *= vars->scale;
	new_pos.x += vars->x_off;
	new_pos.y += vars->y_off;
	return (new_pos);
}
