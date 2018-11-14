/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 23:35:31 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/11 17:03:51 by kmckee           ###   ########.fr       */
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
	v->width = WIDTH;
	v->height = HEIGHT;
	v->max_iter = 40;
	v->mouse_x = WIDTH / 2;
	v->mouse_y = HEIGHT / 2;
	v->space = 2;
	v->zoom = 1;
	v->min_re = -2.2;
	v->max_re = 2.2;
	v->min_im = -2.0;
	v->max_im = v->min_im + (v->max_re - v->min_re) * v->height / v->width;
	v->re_factor = (v->max_re - v->min_re) / (v->width);
	v->im_factor = (v->max_im - v->min_im) / (v->height);
	v->color = 1;
	v->color_shift = 0;
	return (v);
}

void	view_reset(t_view *v, int type)
{
	v->width = WIDTH;
	v->height = HEIGHT;
	v->max_iter = 40;
	v->mouse_x = WIDTH / 2;
	v->mouse_y = HEIGHT / 2;
	v->space = 2;
	v->zoom = 1;
	v->min_re = -2.2;
	v->max_re = 2.2;
	v->min_im = -2.0;
	v->max_im = v->min_im + (v->max_re - v->min_re) * v->height / v->width;
	v->re_factor = (v->max_re - v->min_re) / (v->width);
	v->im_factor = (v->max_im - v->min_im) / (v->height);
	v->color = 1;
	v->color_shift = 0;
	v->fractol = type;
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
