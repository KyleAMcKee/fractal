/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 13:04:06 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/11 17:44:34 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	*fractal_draw(void *arg)
{
	t_thread	*thread;
	t_view		*view;
	int			y;
	int			height;

	thread = (t_thread*)arg;
	view = thread->view;
	height = (thread->count * 300) + 300;
	y = 300 * thread->count - 1;
	while (y++ < height)
	{
		if (view->fractol == 1)
			mandelbrot_draw(view, y);
		else if (view->fractol == 2)
			julia_draw(view, view->mouse_x, view->mouse_y, y);
		else if (view->fractol == 3)
			burning_ship_draw(view, y);
		else if (view->fractol == 4)
			swirl_draw(view, y);
		else if (view->fractol == 5)
			spiral_draw(view, y);
		else if (view->fractol == 6)
			fingerprint_draw(view, y);
	}
	return (view);
}

int		fractal_create(t_view *view)
{
	int			i;
	t_thread	*thread;
	pthread_t	tid[4];

	i = -1;
	thread = ft_memalloc(sizeof(t_thread) * 4);
	while (++i < 4)
	{
		thread[i].view = view;
		thread[i].count = i;
		pthread_create(&tid[i], NULL, fractal_draw, &thread[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(tid[i], NULL);
	put_image(view);
	create_image(view);
	free(thread);
	return (0);
}
