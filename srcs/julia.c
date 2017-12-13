/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:13:49 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/12 19:31:39 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_draw(t_view *v, int mouse_x, int mouse_y, int y)
{
	double  c_im;
    double  c_re;
    double  z_re;
    double  z_im;
    double  z_im2;
    double  z_re2;
    int     x;
    int     i;

	i = 0;
	x = 0;
	v->reFactor = (v->maxRe - v->minRe) / v->width / v->zoom;
	v->imFactor = (v->maxIm - v->minIm) / v->width / v->zoom;
	c_im = (mouse_y * v->imFactor); /// v->zoom;
 	c_re = (mouse_x * v->reFactor); /// v->zoom;
	while (x < v->width)
	{
		z_re = v->minRe + (x * v->reFactor);// / v->zoom;
		z_im = v->maxIm - (y * v->imFactor);// / v->zoom;
		while (i < v->max_iter && z_re + z_im <= 4)
		{
			z_re2 = z_re * z_re;
			z_im2 = z_im * z_im;
			if (z_re2 + z_im2 > 4)
				break ;
			z_im = 2 * z_re * z_im + c_im;
			z_re = z_re2 - z_im2 + c_re;
			i++;
		}
		if (i < v->max_iter)
			rainbow(v, x, y, i);
		else
			put_pixel(v, x, y, 0x000000);
		x++;
		i = 0;
	}
}
