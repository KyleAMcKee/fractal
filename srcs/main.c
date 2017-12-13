/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:08:00 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/11 22:01:06 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include "../mlx/mlx.h"
#include "../libft/libft.h"

int	set_fractol(char *str, t_view *view)
{
	if (ft_strequ("mandelbrot", str))
		view->fractol = 1;
	else if (ft_strequ("julia", str))
		view->fractol = 2;
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_view	*view;

	i = 0;
	if (argc >= 2)
	{
		while (++i < argc)
		{
			view = view_init();
			if (set_fractol(argv[i], view))
			{
				view->mlx = mlx_init();
				create_image(view);
				view->win = mlx_new_window(view->mlx, view->width,
				view->height, argv[i]);
				fractal_create(view);
				init_hooks(view);
				mlx_loop(view->mlx);
			}
			else
				usage();
		}
	}
	else
		usage();
	return (0);
}
