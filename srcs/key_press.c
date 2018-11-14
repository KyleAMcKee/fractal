/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:51:21 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/11 10:10:45 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_fractal(int keycode, t_view *view)
{
	if (keycode == ZERO)
		view_reset(view, 1);
	if (keycode == NINE)
		view_reset(view, 2);
	if (keycode == EIGHT)
		view_reset(view, 3);
	if (keycode == SEVEN)
		view_reset(view, 4);
	if (keycode == SIX)
		view_reset(view, 5);
	if (keycode == FIVE)
		view_reset(view, 6);
	if (keycode == KEY_R)
		view_reset(view, view->fractol);
	if (keycode == ESC)
		exit(1);
	if (keycode == KEY_W)
		move_up(view);
	if (keycode == KEY_A)
		move_left(view);
	if (keycode == KEY_S)
		move_down(view);
	if (keycode == KEY_D)
		move_right(view);
}

void	check_color(int keycode, t_view *view)
{
	if (keycode == ONE)
		view->color = 1;
	if (keycode == TWO)
		view->color = 2;
	if (keycode == THREE)
		view->color = 3;
	if (keycode == KEY_C)
	{
		view->color_shift += 1;
		if (view->color_shift > 16)
			view->color_shift = 0;
	}
	if (keycode == SPACE)
		view->space += 1;
	if (keycode == UP_ARROW)
		view->max_iter += 5;
	if (keycode == DOWN_ARROW)
		view->max_iter -= 5;
}

int		key_press(int keycode, t_view *view)
{
	if (keycode == KEY_PLUS)
	{
		view->zoom *= 1.2;
		view->min_re += (80 * view->re_factor) / view->zoom;
		view->max_re += (80 * view->re_factor) / view->zoom;
		view->min_im -= (80 * view->im_factor) / view->zoom;
		view->max_im -= (80 * view->im_factor) / view->zoom;
	}
	if (keycode == KEY_MINUS)
	{
		view->zoom /= 1.2;
		view->min_re += ((-80 / 1.2) * view->re_factor) / view->zoom;
		view->max_re += ((-80 / 1.2) * view->re_factor) / view->zoom;
		view->min_im -= ((-80 / 1.2) * view->im_factor) / view->zoom;
		view->max_im -= ((-80 / 1.2) * view->im_factor) / view->zoom;
	}
	check_fractal(keycode, view);
	check_color(keycode, view);
	fractal_create(view);
	return (0);
}

void	init_hooks(t_view *view)
{
	mlx_hook(view->win, 6, 0, motion_hook, view);
	mlx_hook(view->win, 2, 0, key_press, view);
	mlx_hook(view->win, 4, 0, mouse_press, view);
}
