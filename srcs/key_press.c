/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:51:21 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/12 20:51:11 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	check_fractal(int keycode, t_view *view)
{
	if (keycode == ZERO)
		view->fractol = 1;
	if (keycode == NINE)
		view->fractol = 2;
}

void	check_color(int keycode, t_view *view)
{
	if (keycode == 18)
		view->color = 1;
	if (keycode == 19)
		view->color = 2;
	if (keycode == 20)
		view->color = 3;
	if (keycode == 21)
		view->color = 4;
	if (keycode == 23)
		view->color = 5;
}

int		key_press(int keycode, t_view *view)
{
	//printf("%d\n", keycode);
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
	if (keycode == SPACE)
		view->space += 1;
	if (keycode == UP_ARROW)
		view->max_iter += 5;
	if (keycode == DOWN_ARROW)
		view->max_iter -= 5;
	if (keycode == KEY_PLUS)
	{
		view->maxRe /= 1.2;
		view->minRe /= 1.2;
		view->maxIm /= 1.2;
		view->minIm /= 1.2;
	}
	if (keycode == KEY_MINUS)
	{
		view->maxRe *= 1.2;
		view->minRe *= 1.2;
		view->maxIm *= 1.2;
		view->minIm *= 1.2;
	}
	if (keycode == KEY_C)
	{
		view->color_shift += 1;
		if (view->color_shift > 16)
			view->color_shift = 0;
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
