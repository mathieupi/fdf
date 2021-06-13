/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:44:49 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/14 00:50:42 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "minilibx/mlx.h"
# include <stdlib.h>
# include "./libft/libft.h"
# define BONUS 0

typedef struct s_map
{
	int	x;
	int	y;
	int	**map;
}		t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_data;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
}	t_coord;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	long	sec;
	t_data	img;
	int		color;
	float	scale_h;
	float	scale;
	int		x_off;
	int		y_off;
	int		angle_yaw;
	int		angle_pitch;
	int		up_to_date;
	t_map	*map;
}				t_vars;

void	start(t_map *map);

#endif
