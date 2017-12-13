/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:45:04 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/11 22:03:42 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_up(t_view *v)
{
	v->minIm -= fabs(v->minIm * 0.1);
	v->maxIm -= fabs(v->maxIm * 0.1);
}

void	move_down(t_view *v)
{
	v->minIm += fabs(v->minIm * 0.1);
	v->maxIm += fabs(v->maxIm * 0.1);
}

void	move_left(t_view *v)
{
	v->minRe += fabs(v->minRe * 0.1);
	v->maxRe += fabs(v->maxRe * 0.1);
}

void	move_right(t_view *v)
{
	v->minRe -= fabs(v->minRe * 0.1);
	v->maxRe -= fabs(v->maxRe * 0.1);
}
