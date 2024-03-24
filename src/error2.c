/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:33:30 by kostya            #+#    #+#             */
/*   Updated: 2021/10/02 19:25:58 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <stdio.h>

void	__print_help_message_extension_1(void);
void	__print_help_message_extension_2(void);

inline void	print_help_message(void)
{
	printf("Usage: Fract-ol [SET] [OPTION]...\r\n"
		"Draw selected fractal with gived options\r\n"
		"\r\n"
		"Mandatory arguments ([SET] option):\r\n"
		"\tmandelbrot, m\t\tdraw mandelbrot set fractal\r\n"
		"\tjulia, j\t\tdraw julia set fractal\r\n"
		"\tnewton, pool, n\t\tdraw newton pool fractal for z^5 - 1\r\n"
		"\r\n"
		"External options ([OPTION] part):\r\n"
		"\r\n\t-R[RESOLUTION]\t\toption set resolution of window,\r\n"
		"\t\t\t\t[RESOLUTION] option should be in format\r\n"
		"\t\t\t\t[RES_X]+[RES_Y] where [RES_X] is integer horisontal,\r\n"
		"\t\t\t\tand [RES_Y] is integer vertical resolution\r\n"
		"\t\t\t\tif parameter not set, it defaults to 800+600\r\n"
		"\r\n\t-c[IMAGE_CENTER]\toption set center coordinates of\r\n"
		"\t\t\t\tshowing image, [IMAGE_CENTER] should be in format:\r\n"
		"\t\t\t\t[REAL_FLOAT]+/-[IMAG_FLOAT]i, where REAL_FLOAT and\r\n"
		"\t\t\t\tIMAG_FLOAT are float numbers of real and imaginary\r\n"
		"\t\t\t\tparts of coordinate\r\n"
		"\t\t\t\tif parameter not set - it defaults 0.5+0i for\r\n"
		"\t\t\t\tmandelbrot set, and 0+0i for julia and newton pool sets\r\n"
		"\r\n\t-w[WIDTH]\t\toption set horisontal zoom (diameter) for image\r\n"
		);
	__print_help_message_extension_1();
	ft_exit(0);
}

inline void	__print_help_message_extension_1(void)
{
	printf(
		"\t\t\t\tin screen. [WIDTH] should be a float number\r\n"
		"\t\t\t\tif parameter not set - it defaults to 3\r\n"
		"\r\n\t-r[RADIUS]\t\toption set the maximum radius, that algorithm\r\n"
		"\t\t\t\twill evaluate as infinitely far away\r\n"
		"\t\t\t\tif parameter is not set - it defaults to 30\r\n"
		"\t\t\t\t[RADIUS] should be a float number, option ignored if\r\n"
		"\t\t\t\tselected set is newton pool\r\n"
		"\r\n\t-p[PARAMETER]\t\toption set external parameter for fractal\r\n"
		"\t\t\t\toption ignored if selected set is mandelbrot or newton pool\r\n"
		"\t\t\t\t[PARAMETER] should be in format:\r\n"
		"\t\t\t\t[REAL_FLOAT]+/-[IMAG_FLOAT]i, where REAL_FLOAT and\r\n"
		"\t\t\t\tIMAG_FLOAT are float numbers of real and imaginary\r\n"
		"\t\t\t\tparts of complex number if selected set is julia\r\n"
		"\t\t\t\tif parameter is not set - it defaults to\r\n"
		"\t\t\t\t-0.74543+0.11301i\r\n"
		"\r\n\t-d[DEPTH]\t\tparameter set maximum requsion depth (iteration\r\n"
		"\t\t\t\tnumber) for compution\r\n"
		"\t\t\t\tif parameter is not set - it defaults to 300\r\n"
		"\r\n\t-s[SCHEME]\t\tparameter set colorscheme for fractal colorizing\r\n"
		"\t\t\t\t[SCHEME should be integer from 1 to 6\r\n"
		"\t\t\t\tif parameter is not set - it defaults to 1 for julia and\r\n"
		"\t\t\t\tmandelbrot, and to 6 for newton pool\r\n"
		);
	__print_help_message_extension_2();
}

inline void	__print_help_message_extension_2(void)
{
	printf(
		"\r\n"
		"Exit status\r\n"
		"\t0\tif OK,\r\n"
		"\tnon 0\tif error occured\r\n"
		"\r\n"
		"Examples\r\n"
		"./Fract-ol m -R1920+1080 -c-0.7436430340132807-0.1318261346682662i \\"
		"\t\r\n-w2e-5 -d1300\r\n"
		"./Fract-ol j -c4e-5i+3e-3 -R800+600 -w1e-3 -d2000\r\n"
		"\r\n"
		"Full information avaliable in:\r\n"
		"\t<https://github.com/tlucanti/Fract-ol>\r\n"
		"\r\n"
		"(Fract-ol v0.2)\t\ttlucanti\r\n"
		);
}
