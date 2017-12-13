/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:58:11 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/12 20:48:22 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	mandelbrot_draw(t_view *v, int y)
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
	v->reFactor = (v->maxRe - v->minRe) / v->width;
	v->imFactor = (v->maxIm - v->minIm) / v->width;
	c_im = v->maxIm - (y * v->imFactor);// / v-> zoom;
	while (x < v->width)
	{
		c_re = v->minRe + (x * v->reFactor); // v->zoom;
		z_re = c_re;
		z_im = c_im;
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
	put_pixel(v, 600, 600, 0xFF0000);
	put_pixel(v, 601, 599, 0xFF0000);
	put_pixel(v, 599, 601, 0xFF0000);
	put_pixel(v, 601, 601, 0xFF0000);
	put_pixel(v, 599, 599, 0xFF0000);
}
