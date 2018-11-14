/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:40:43 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/11 10:18:02 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	motion_hook(int x, int y, t_view *view)
{
	if (view->fractol == 2 && view->space % 2 == 0)
	{
		view->mouse_x = x - (WIDTH / 2);
		view->mouse_y = y - (HEIGHT / 2);
		fractal_create(view);
	}
	return (0);
}

int	mouse_press(int button, int x, int y, t_view *v)
{
	if (button == 1)
	{
		v->min_re += ((x - (HEIGHT / 2)) * v->re_factor) / v->zoom;
		v->max_re += ((x - (HEIGHT / 2)) * v->re_factor) / v->zoom;
		v->min_im -= ((y - (WIDTH / 2)) * v->im_factor) / v->zoom;
		v->max_im -= ((y - (WIDTH / 2)) * v->im_factor) / v->zoom;
		fractal_create(v);
	}
	if (button == 4)
		key_press(KEY_MINUS, v);
	if (button == 5)
		key_press(KEY_PLUS, v);
	return (0);
}
