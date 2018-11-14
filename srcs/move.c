/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:45:04 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/11 10:17:01 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_up(t_view *v)
{
	v->min_im += (100 * v->im_factor) / v->zoom;
	v->max_im += (100 * v->im_factor) / v->zoom;
}

void	move_down(t_view *v)
{
	v->min_im -= (100 * v->im_factor) / v->zoom;
	v->max_im -= (100 * v->im_factor) / v->zoom;
}

void	move_left(t_view *v)
{
	v->min_re -= (100 * v->im_factor) / v->zoom;
	v->max_re -= (100 * v->im_factor) / v->zoom;
}

void	move_right(t_view *v)
{
	v->min_re += (100 * v->im_factor) / v->zoom;
	v->max_re += (100 * v->im_factor) / v->zoom;
}
