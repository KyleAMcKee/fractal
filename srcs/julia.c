/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:13:49 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/11 10:14:00 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

t_frac	set_constants(t_view *v, int mouse_x, int mouse_y)
{
	t_frac vars;

	if (v->space % 2 != 0)
	{
		vars.c_im = (v->mouse_y1 * v->im_factor);
		vars.c_re = (v->mouse_x1 * v->re_factor);
	}
	else
	{
		vars.c_im = (mouse_y * v->im_factor) / v->zoom;
		vars.c_re = (mouse_x * v->re_factor) / v->zoom;
		v->mouse_x1 = v->mouse_x;
		v->mouse_y1 = v->mouse_y;
	}
	return (vars);
}

void	julia_draw(t_view *v, int mouse_x, int mouse_y, int y)
{
	t_frac	vars;

	vars = set_constants(v, mouse_x, mouse_y);
	vars.i = -1;
	vars.x = -1;
	while (vars.x++ < v->width)
	{
		vars.z_re = v->min_re + (vars.x * v->re_factor) / v->zoom;
		vars.z_im = v->max_im - (y * v->im_factor) / v->zoom;
		while (vars.i++ < v->max_iter && vars.z_re + vars.z_im <= 4)
		{
			vars.z_re2 = vars.z_re * vars.z_re;
			vars.z_im2 = vars.z_im * vars.z_im;
			if (vars.z_re2 + vars.z_im2 > 4)
				break ;
			vars.z_im = 2 * vars.z_re * vars.z_im + vars.c_im;
			vars.z_re = vars.z_re2 - vars.z_im2 + vars.c_re;
		}
		if (vars.i < v->max_iter)
			color(v, vars.x, y, vars.i);
		else
			put_pixel(v, vars.x, y, 0x000000);
		vars.i = -1;
	}
}
