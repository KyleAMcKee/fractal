/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 13:04:06 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/12 17:34:39 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*fractal_draw(void *arg)
{
	t_thread	*thread;
	t_view		*view;
	int			y;
	int			height;

	thread = (t_thread*)arg;
	view = thread->view;
	height = (thread->count * 300) + 300;
	y = 300 * thread->count;
	while (y < height)
	{
		if (view->fractol == 1)
			mandelbrot_draw(view, y);
		else if (view->fractol == 2)
			julia_draw(view, view->mouse_x, view->mouse_y, y);
		y++;
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
	{
		pthread_join(tid[i], NULL);
	}
	put_image(view);
	create_image(view);
	free(thread);
	return (0);
}
