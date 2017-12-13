/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:40:43 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/12 21:01:15 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int motion_hook(int x, int y, t_view *view)
{
	if (view->fractol == 2 && view->space % 2 == 0)
	{
		view->mouse_x = x;
		view->mouse_y = y;
		fractal_create(view);
	}
	return (0);
}

int mouse_press(int button, int x, int y, t_view *v)
{
	int i;

	i = -1;
	/* CENTER IMAGE ON CLICK */
	if (button == 1)
	{
		fractal_create(v);
		v->minRe += ((x - 600)  * v->reFactor);// / v->zoom;
		v->maxRe += ((x - 600) * v->reFactor);// / v->zoom;
		v->minIm -= ((y - 600)  * v->imFactor);// / v->zoom;
		v->maxIm -= ((y - 600) * v->imFactor);// / v->zoom;
		//v->reFactor = (v->maxRe - v->minRe) / v->width;
		//v->imFactor = (v->maxIm - v->minIm) / v->width;
		fractal_create(v);
	}
	/* ZOOM OUT */
	if (button == 4)
	{
		v-> zoom /= 1.25;
		//v->minRe /= 1.25;// += (((x - 600)  * v->reFactor) / v->zoom) / 10;
		//v->maxRe /= 1.25;//+= (((x - 600) * v->reFactor) / v->zoom) / 10;
		//v->minIm /= 1.25;//-= (((y - 600)  * v->imFactor) / v->zoom) / 10;
		//v->maxIm /= 1.25;//-= (((y - 600) * v->imFactor) / v->zoom) / 10;
		//v->reFactor = (v->maxRe - v->minRe) / v->width;
		//v->imFactor = (v->maxIm - v->minIm) / v->height;
		fractal_create(v);
	}
	/* ZOOM IN */
	if (button == 5)
	{
		v->zoom *= 1.25;
		//v->minRe *= 1.25;//+= (((x - 600)  * v->reFactor) / v->zoom) / 10;
		//v->maxRe *= 1.25;//+= (((x - 600) * v->reFactor)/ v->zoom) / 10;
		//v->minIm *= 1.25;//-= (((y - 600)  * v->imFactor) / v->zoom) / 10;
		//v->maxIm *= 1.25;//-= (((y - 600) * v->imFactor) / v->zoom) / 10;
		//v->reFactor = (v->maxRe - v->minRe) / v->width;
		//v->imFactor = (v->maxIm - v->minIm) / v->height;
		fractal_create(v);

	}
	return (0);
}
