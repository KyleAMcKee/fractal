/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 23:35:31 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/12 21:27:04 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_view *view, int x, int y, int color)
{
	int i;

	if (x < view->width && y < view->height)
	{
		i = (x * (view->bpp / 8)) + (y * view->size_line);
		view->pixel_str[i] = color;
		view->pixel_str[++i] = color >> 8;
		view->pixel_str[++i] = color >> 16;
	}
}

t_view	*view_init(void)
{
	t_view *v;

	v = (t_view*)malloc(sizeof(t_view));
	v->width = 1200;
	v->height = 1200;
	v->max_iter = 50;
	v->mouse_x = 600;
	v->mouse_y = 600;
	v->space = 2;
	v->zoom = 1;
	v->minRe = -2;//-2.2;
	v->maxRe = 2;
	v->minIm = -2;//-1.2;
	v->maxIm = 2;//2.0;//v->minIm + (v->maxRe - v->minRe) * v->height / v->width;
	v->reFactor = (v->maxRe - v->minRe) / (v->width);
	v->imFactor = (v->maxIm - v->minIm) / (v->height);
	v->color = 1;
	v->color_shift = 0;
	return (v);
}

void	create_image(t_view *view)
{
	view->img = mlx_new_image(view->mlx, view->width, view->height);
	view->pixel_str = mlx_get_data_addr(view->img, &(view->bpp),
			&(view->size_line), &(view->endian));
}

void	put_image(t_view *view)
{
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	mlx_destroy_image(view->mlx, view->img);
}
