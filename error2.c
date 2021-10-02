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

void	__print_help_message_extension_1(void);
void	__print_help_message_extension_2(void);

inline void	print_help_message(void)
{
	printf("Usage: Fract-ol [SET] [OPTION]...\n"
		"Draw selected fractal with gived options\n"
		"\n"
		"Mandatory arguments ([SET] option):\n"
		"\tmandelbrot, m\t\tdraw mandelbrot set fractal\n"
		"\tjulia, j\t\tdraw julia set fractal\n"
		"\tnewton, pool, n\t\tdraw newton pool fractal for z^5 - 1\n"
		"\n"
		"External options ([OPTION] part):\n"
		"\n\t-R[RESOLUTION]\t\toption set resolution of window,\n"
		"\t\t\t\t[RESOLUTION] option should be in format\n"
		"\t\t\t\t[RES_X]+[RES_Y] where [RES_X] is integer horisontal,\n"
		"\t\t\t\tand [RES_Y] is integer vertical resolution\n"
		"\t\t\t\tif parameter not set, it defaults to 800+600\n"
		"\n\t-c[IMAGE_CENTER]\toption set center coordinates of\n"
		"\t\t\t\tshowing image, [IMAGE_CENTER] should be in format:\n"
		"\t\t\t\t[REAL_FLOAT]+/-[IMAG_FLOAT]i, where REAL_FLOAT and\n"
		"\t\t\t\tIMAG_FLOAT are float numbers of real and imaginary\n"
		"\t\t\t\tparts of coordinate\n"
		"\t\t\t\tif parameter not set - it defaults 0.5+0i for\n"
		"\t\t\t\tmandelbrot set, and 0+0i for julia and newton pool sets\n"
		"\n\t-w[WIDTH]\t\toption set horisontal zoom (diameter) for image\n"
		);
	__print_help_message_extension_1();
	ft_exit(0);
}

inline void	__print_help_message_extension_1(void)
{
	printf(
		"\t\t\t\tin screen. [WIDTH] should be a float number\n"
		"\t\t\t\tif parameter not set - it defaults to 3\n"
		"\n\t-r[RADIUS]\t\toption set the maximum radius, that algorithm\n"
		"\t\t\t\twill evaluate as infinitely far away\n"
		"\t\t\t\tif parameter is not set - it defaults to 30\n"
		"\t\t\t\t[RADIUS] should be a float number, option ignored if\n"
		"\t\t\t\tselected set is newton pool\n"
		"\n\t-p[PARAMETER]\t\toption set external parameter for fractal\n"
		"\t\t\t\toption ignored if selected set is mandelbrot or newton pool\n"
		"\t\t\t\t[PARAMETER] should be in format:\n"
		"\t\t\t\t[REAL_FLOAT]+/-[IMAG_FLOAT]i, where REAL_FLOAT and\n"
		"\t\t\t\tIMAG_FLOAT are float numbers of real and imaginary\n"
		"\t\t\t\tparts of complex number if selected set is julia\n"
		"\t\t\t\tif parameter is not set - it defaults to\n"
		"\t\t\t\t-0.74543+0.11301i\n"
		"\n\t-d[DEPTH]\t\tparameter set maximum requsion depth (iteration\n"
		"\t\t\t\tnumber) for compution\n"
		"\t\t\t\tif parameter is not set - it defaults to 300\n"
		"\n\t-s[SCHEME]\t\tparameter set colorscheme for fractal colorizing\n"
		"\t\t\t\t[SCHEME should be integer from 1 to 6\n"
		"\t\t\t\tif parameter is not set - it defaults to 1 for julia and\n"
		"\t\t\t\tmandelbrot, and to 6 for newton pool\n"
		);
	__print_help_message_extension_2();
}

inline void	__print_help_message_extension_2(void)
{
	printf(
		"\n"
		"Exit status\n"
		"\t0\tif OK,\n"
		"\tnon 0\tif error occured\n"
		"\n"
		"Examples\n"
		"./Fract-ol m -R1920+1080 -c-0.7436430340132807-0.1318261346682662i \\"
		"\t\n-w2e-5 -d1300\n"
		"./Fract-ol j -c4e-5i+3e-3 -R800+600 -w1e-3 -d\n"
		"\n"
		"Full information avaliable in:\n"
		"\t<https://github.com/antikostya/Fract-ol>\n"
		"\n"
		"(Fract-ol v0.2)\t\ttlucanti\n"
		);
}
