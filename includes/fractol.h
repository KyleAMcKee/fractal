/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:07:41 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/29 17:25:51 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <pthread.h>

# define HEIGHT 800
# define WIDTH 800
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_C 8
# define KEY_W 13
# define KEY_R 15
# define SPACE 49
# define UP_ARROW 126
# define DOWN_ARROW 125
# define KEY_PLUS 69
# define KEY_MINUS 78
# define ESC 53
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21
# define FIVE 23
# define SIX 22
# define SEVEN 26
# define EIGHT 28
# define NINE 25
# define ZERO 29
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
	int		mouse_x1;
	int		mouse_y1;
	int		max_iter;
	double	zoom;
	double	max_im;
	double	min_im;
	double	max_re;
	double	min_re;
	double	im_factor;
	double	re_factor;
	int		bpp;
	int		size_line;
	int		endian;
	char	*pixel_str;
	int		fractol;
	int		space;
	int		color;
	int		color_shift;
}				t_view;

typedef struct	s_frac
{
	double	c_im;
	double	c_re;
	double	z_re;
	double	z_im;
	double	z_im2;
	double	z_re2;
	int		x;
	int		i;
}				t_frac;

typedef	struct	s_thread
{
	t_view	*view;
	int		count;
}				t_thread;

void			mandelbrot_draw(t_view *view, int y);
void			julia_draw(t_view *view, int mouse_x, int mouse_y, int y);
void			burning_ship_draw(t_view *v, int y);
void			swirl_draw(t_view *view, int y);
void			clover_draw(t_view *view, int y);
void			spiral_draw(t_view *view, int y);
void			fingerprint_draw(t_view *view, int y);

void			color(t_view *view, int x, int y, int i);
int				key_press(int keycode, t_view *view);
int				motion_hook(int x, int y, t_view *view);
int				mouse_press(int button, int x, int y, t_view *v);
void			put_pixel(t_view *view, int x, int y, int color);

void			move_up(t_view *view);
void			move_left(t_view *view);
void			move_down(t_view *view);
void			move_right(t_view *view);
void			init_hooks(t_view *view);

void			error(int i, char *str);
void			display_usage(void);

t_view			*view_init(void);
void			view_reset(t_view *view, int type);
void			create_image(t_view *view);
void			put_image(t_view *view);

void			*fractal_draw(void *arg);
int				fractal_create(t_view *view);
#endif
