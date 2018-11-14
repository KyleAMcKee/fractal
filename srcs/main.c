/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:08:00 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/11 17:02:33 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

int		set_frac(char *str, t_view *view, int *flag)
{
	if (ft_strequ("mandelbrot", str))
		view->fractol = 1;
	else if (ft_strequ("julia", str))
		view->fractol = 2;
	else if (ft_strequ("burningship", str))
		view->fractol = 3;
	else if (ft_strequ("swirl", str))
		view->fractol = 4;
	else if (ft_strequ("spiral", str))
		view->fractol = 5;
	else if (ft_strequ("fingerprint", str))
		view->fractol = 6;
	else
		return (0);
	return (++*flag);
}

void	frac_in(t_view *view[], void *mlx, int i)
{
	view[i]->mlx = mlx;
	create_image(view[i]);
	view[i]->win = mlx_new_window(mlx, view[i]->width,
	view[i]->height, "Fractol");
	fractal_create(view[i]);
	init_hooks(view[i]);
}

int		main(int argc, char **av)
{
	int		i;
	void	*mlx;
	int		f;
	t_view	*v[argc];

	i = 0;
	f = 0;
	if (argc >= 2)
	{
		mlx = mlx_init();
		while (++i < argc)
		{
			v[i] = view_init();
			(set_frac(av[i], v[i], &f)) ? frac_in(v, mlx, i) : error(1, av[i]);
		}
		f ? display_usage() : error(3, "");
		if (!f)
			return (0);
		mlx_loop(mlx);
	}
	else
		error(2, "");
	return (0);
}
