/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 13:18:21 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/21 14:22:16 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color(t_view *view, int x, int y, int i)
{
	static int	full_spectrum[] = {
		0xE50016, 0xE23D00, 0xDF9000, 0xD9DD00, 0x85DA00,
		0x33D800, 0x005D1C, 0x00D36A, 0x00D0B6, 0x009ACE,
		0x004DCB, 0x0001C9, 0x4800C6, 0x9000C4, 0xC100AC, 0xBF0062
	};
	static int	blue_brown[] = {
		0x421E0F, 0x351821, 0x2D152D, 0x1F0F42, 0x1E1D4C,
		0x1C486C, 0x1A728B, 0x189DAB, 0x17BAC0, 0xDCF637,
		0xD8D826, 0xD3B513, 0xCFAA38, 0xAF912E, 0x8F7924
	};
	static int	peacock[] = {
		0xC0F862, 0x10A690, 0x1166A3, 0x3D4987, 0x402B6D,
		0x55C6D0, 0x101CBA, 0x0E8516, 0x64C726, 0x9F7F4E,
		0x4D528C, 0x471A41, 0xE6DAE8, 0x61CEBB, 0x578E71, 0xADB02B
	};

	if (view->color == 1)
		put_pixel(view, x, y, full_spectrum[(i + view->color_shift) % 16]);
	else if (view->color == 2)
		put_pixel(view, x, y, blue_brown[(i + view->color_shift) % 16]);
	else if (view->color == 3)
		put_pixel(view, x, y, peacock[(i + view->color_shift) % 16]);
}
