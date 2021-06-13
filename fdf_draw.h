/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:55:58 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/11 18:37:03 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DRAW_H
# define FDF_DRAW_H
# include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_point(t_data *data, t_point a, int size, int color);
void	draw_line(t_data *data, t_point a, t_point b, int color);
void	draw_map(t_vars *vars, t_map *map);

#endif
