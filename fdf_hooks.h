/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:55:58 by mmehran           #+#    #+#             */
/*   Updated: 2021/06/14 00:41:33 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HOOKS_H
# define FDF_HOOKS_H
# include "fdf.h"

# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_LEFT 123
# define KEY_W 13
# define KEY_S 1
# define KEY_ESC 53
# define KEY_T 17
# define KEY_G 5
# define KEY_H 4
# define KEY_F 3
# define KEY_U 32
# define KEY_J 38

int	key_hook(int keycode, t_vars *vars);

#endif
