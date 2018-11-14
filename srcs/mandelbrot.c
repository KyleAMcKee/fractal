/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:58:11 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/11 10:11:34 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_draw(t_view *v, int y)
{
	t_frac	vars;

	vars.i = -1;
	vars.x = -1;
	vars.c_im = v->max_im - (y * v->im_factor) / v->zoom;
	while (vars.x++ < v->width)
	{
		vars.c_re = v->min_re + (vars.x * v->re_factor) / v->zoom;
		vars.z_re = vars.c_re;
		vars.z_im = vars.c_im;
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
