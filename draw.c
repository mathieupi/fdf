/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:21:51 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/13 23:59:56 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_draw.h"
#include "fdf_transform.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y >= data->h || y < 0 || x < 0 || x >= data->w)
		return ;
	dst = data->addr;
	dst += y * data->line_length;
	dst += x * (data->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

void	draw_point(t_data *data, t_point a, int size, int color)
{
	int	x;
	int	y;

	x = a.x - size / 2;
	while (x < a.x + size / 2)
	{
		y = a.y - size / 2;
		while (y < a.y + size / 2)
		{
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_line(t_data *data, t_point a, t_point b, int color)
{
	int		delta_x;
	int		delta_y;
	int		step;
	int		i;

	i = 0;
	delta_x = b.x - a.x;
	delta_y = b.y - a.y;
	step = abs(delta_y);
	if (abs(delta_x) > abs(delta_y))
		step = abs(delta_x);
	while (i <= step)
	{
		my_mlx_pixel_put(data, a.x, a.y, color);
		a.x += (double) delta_x / (double) step;
		a.y += (double) delta_y / (double) step;
		i++;
	}
}

int	color(int height)
{
	return ((0x00FF0000 + height * 15) & 0x00FFFFFF);
}

void	draw_map(t_vars *vars, t_map *map)
{
	t_point	curr;
	t_point	next;
	int		i;
	int		j;

	i = -1;
	while (++i < map->y)
	{
		j = -1;
		while (++j < map->x)
		{
			curr = transform((t_coord){j, i, map->map[i][j]}, vars);
			if (j < map->x - 1)
			{
				next = transform((t_coord){j + 1, i, map->map[i][j + 1]}, vars);
				draw_line(&vars->img, curr, next, color(map->map[i][j]));
			}
			if (i < map->y - 1)
			{
				next = transform((t_coord){j, i + 1, map->map[i + 1][j]}, vars);
				draw_line(&vars->img, curr, next, color(map->map[i][j]));
			}
		}
	}
}
