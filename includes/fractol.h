/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:07:41 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/12 15:27:06 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <pthread.h>

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_C 8
# define KEY_W 13
# define SPACE 49
# define ZERO 29
# define NINE 25
# define UP_ARROW 126
# define DOWN_ARROW 125
# define KEY_PLUS 69
# define KEY_MINUS 78
# define ESC 53
# define THREADS 4

typedef struct	s_view
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;
	int		mouse_x;
	int		mouse_y;
	int		max_iter;
	double	zoom;
	double	maxIm;
	double	minIm;
	double	maxRe;
	double	minRe;
	double	imFactor;
	double	reFactor;
	int		bpp;
	int		size_line;
	int		endian;
	char	*pixel_str;
	int		fractol;
	int		space;
	int		color;
	int		color_shift;
}				t_view;

typedef	struct	s_thread
{
	t_view	*view;
	int		count;
}				t_thread;

void	rainbow(t_view *view, int x, int y, int i);
void	mandelbrot_draw(t_view *view, int y);
void	julia_draw(t_view *view, int mouse_x, int mouse_y, int y);
int		key_press(int keycode, t_view *view);
int		motion_hook(int x, int y, t_view *view);
int		mouse_press(int button, int x, int y, t_view *v);
void	put_pixel(t_view *view, int x, int y, int color);

void	move_up(t_view *view);
void	move_left(t_view *view);
void	move_down(t_view *view);
void	move_right(t_view *view);
void	init_hooks(t_view *view);

t_view	*view_init(void);
void	create_image(t_view *view);
void	put_image(t_view *view);

void	usage(void);

void	*fractal_draw(void *arg);
int		fractal_create(t_view *view);
#endif
