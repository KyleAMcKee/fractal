/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:26:51 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/11 18:57:19 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "color.h"

void	error(int i, char *str)
{
	if (i == 1)
	{
		ft_putstr(RED);
		ft_putstr(str);
		ft_putstr(RESET);
		ft_putstr(" is an invalid fractal, usage is: ");
		ft_putstr("./fractol "GREEN"[input1] [input2]"RESET"...\n");
	}
	if (i == 2)
	{
		ft_putstr(RED"\nNo fractal entered! "RESET);
		ft_putstr("usage is: ./fractol "GREEN"[input1] [input2]"RESET"...\n");
		ft_putstr("\nOptions are:\n"GREEN"mandelbrot");
		ft_putstr("     julia\n""burningship");
		ft_putstr("    swirl\nspiral         fingerprint\n"RESET);
	}
	if (i == 3)
	{
		ft_putstr(RED"\nNo valid fractal entered! "RESET);
		ft_putstr("\nOptions are:\n"GREEN"mandelbrot");
		ft_putstr("     julia\n""burningship");
		ft_putstr("    swirl\nspiral         fingerprint\n"RESET);
	}
}

void	color_usage(void)
{
	ft_putstr(MAGENTA "[1]" RESET " rainbow\n");
	ft_putstr(MAGENTA "[2]" RESET " desert\n");
	ft_putstr(MAGENTA "[3]" RESET " peacock\n");
	ft_putstr(MAGENTA "[C]" RESET " Shift color range\n");
}

void	zoom_usage(void)
{
	ft_putstr(YELLOW "[+]" RESET " Zoom in\n");
	ft_putstr(YELLOW "[-]" RESET " Zoom out\n");
	ft_putstr(YELLOW "[mouse wheel forward]" RESET " Zoom in\n");
	ft_putstr(YELLOW "[mouse wheel backward]" RESET " Zoom out\n");
	ft_putstr(YELLOW "[mouse click]" RESET);
	ft_putstr(" Clicked point centered on screen\n");
}

void	fractal_options(void)
{
	ft_putstr("\nFractal Options\n");
	ft_putstr(CYAN"[0]"RESET" mandelbrot\n");
	ft_putstr(CYAN"[9]"RESET" julia\n");
	ft_putstr(CYAN"[8]"RESET" burning Ship\n");
	ft_putstr(CYAN"[7]"RESET" swirl\n");
	ft_putstr(CYAN"[6]"RESET" spiral\n");
	ft_putstr(CYAN"[5]"RESET" fingerprint\n");
}

void	display_usage(void)
{
	ft_putstr("\nGeneral Usage:\n");
	ft_putstr(RED "[Esc]" RESET " Exit program\n");
	ft_putstr(RED "[R]" RESET " Reset view\n");
	ft_putstr(RED "[Up arrow]" RESET " Increase iterations\n");
	ft_putstr(RED "[Down arrow]" RESET " Decrease iterations\n\n");
	ft_putstr(GREEN "[W]" RESET " Move up\n");
	ft_putstr(GREEN "[A]" RESET " Move left\n");
	ft_putstr(GREEN "[S]" RESET " Move down\n");
	ft_putstr(GREEN "[D]" RESET " Move right\n\n");
	zoom_usage();
	ft_putstr("\nColor Options:\n");
	color_usage();
	fractal_options();
}
