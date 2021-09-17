/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:34:33 by kostya            #+#    #+#             */
/*   Updated: 2021/09/17 23:58:35 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "color.h"

static const char	*ft_strerror(int errorcode);
void	print_help_message_1(void);

void	ft_message(const char *type, const char *parent, int errorcode, char *message)
{
	const char	*type_chr;

	if ((void *)type == (void *)ERROR)
		type_chr = "FAIL";
	else if ((void *)type == (void *)WARNING)
		type_chr = "WARN";
	else if ((void *)type == (void *)OK)
		type_chr = " OK ";
	else if ((void *)type == (void *)INFO)
		type_chr = "INFO";
	printf("%s[%s]%s ", type, type_chr, RESET);
	if (parent)
		printf("%s%s:%s ", TERM_WHITE, parent, RESET);
	printf("%s", ft_strerror(errorcode));
	if (message)
		printf(": %s%s%s\n", WARNING, message, RESET);
	else
		printf("\n");
}

inline void	ft_perror(const char *parent, int errorcode, char *message)
{
	ft_message(ERROR, parent, errorcode, message);
}

inline void	ft_warning(const char *parent, int errorcode, char *message)
{
	ft_message(WARNING, parent, errorcode, message);
}

inline void	ft_info(const char *parent, int errorcode, char *message)
{
	ft_message(INFO, parent, errorcode, message);
}

inline void	ft_ok(const char *parent, int errorcode, char *message)
{
	ft_message(OK, parent, errorcode, message);
}

void	ft_exit(int status)
{
	exit(status);
}

inline void	ft_perror_exit(const char *parent, int errorcode, char *message, int status)
{
	ft_perror(parent, errorcode, message);
	ft_exit(status);
}

inline void	print_help_message_1(void)
{
	printf(
		"\t-r[RADIUS]\t\toption set the maximum radius, that algorithm\n"
		"\t\t\t\twill evaluate as infinitely far away\n"
		"\t\t\t\tif parameter is not set - it defaults to 30\n\n"
		"\t-p[PARAMETER]\t\toption set external parameter for julia set\n"
		"\t\t\t\t[PARAMETER] should be in format:\n"
		"\t\t\t\t[REAL_FLOAT]+[IMAG_FLOAT]i, where REAL_FLOAT and\n"
		"\t\t\t\tIMAG_FLOAT are float numbers of real and imaginary\n"
		"\t\t\t\tparts of complex number\n"
		"\t\t\t\tif parameter is not set - it defaults to\n"
		"\t\t\t\t-0.74543+0.11301i. Parameter is ignored, if selected\n"
		"\t\t\t\tfractal is not mandelbrot\n"
		"\t-d[DEPTH]\t\tparameter set maximum requsion depth (iteration\n"
		"\t\t\t\tnumber) for compution\n"
		"\t\t\t\tif parameter is not set - it defaults to 300\n\n"
		"Exit status\n"
		"\t0\tif OK,\n"
		"\tnon 0\tif error occured\n\n"
		"Examples\n"
		"./Fract-ol m -R1920+1080 -c-0.7436447860+0.131825253i \\\n"
		"\t-w0.29336e-5\n"
		"./Fract-ol j -c4e-5i+3e-3 -R800+600 -w1e-3\n\n"
		"Full information avaliable in:\n"
		"\t<https://github.com/antikostya/Fract-ol>\n"
		);
}

inline void	print_help_message(void)
{
	printf("Usage: Fract-ol [SET] [OPTION]...\n"
		"Draw selected fractal with gived options\n\n"
		"Mandatory arguments ([SET] option):\n"
		"\tmandelbrot, m\t\tdraw mandelbrot set fractal\n"
		"\tjulia, j\t\tdraw julia set fractal\n"
		"\n"
		"External options ([OPTION] options):\n"
		"\t-R[RESOLUTION]\t\toption set resolution of window,\n"
		"\t\t\t\t[RESOLUTION] option should be in format\n"
		"\t\t\t\t[RES_X]+[RES_Y] where [RES_X] is integer horisontal,\n"
		"\t\t\t\tand [RES_Y] is integer vertical resolution\n"
		"\t\t\t\tif parameter not set, it defaults to 800+600\n"
		"\t-c[IMAGE_CENTER]\toption set center coordinates of\n"
		"\t\t\t\tshowing image, [IMAGE_CENTER] should be in format:\n"
		"\t\t\t\t[REAL_FLOAT]+[IMAG_FLOAT]i, where REAL_FLOAT and\n"
		"\t\t\t\tIMAG_FLOAT are float numbers of real and imaginary\n"
		"\t\t\t\tparts of coordinate\n"
		"\t\t\t\tif parameter not set - it defaults 0.5+0i for\n"
		"\t\t\t\tmandelbrot set, and 0+0i for julia set\n"
		"\t-w[WIDTH]\t\toption set horisontal zoom (diameter) for image\n"
		"\t\t\t\tin screen. [WIDTH] should be float number\n"
		"\t\t\t\tif parameter not set - it defaults to 3\n"
		);
	print_help_message_1();
	ft_exit(0);
}

inline void	ft_info_exit(const char *parent, int errorcode, char *message)
{
	ft_perror(parent, errorcode, message);
	ft_info("fract-ol", PARAM_INFO, NULL);
	ft_exit(1);
}

static const char	*ft_strerror(int errorcode)
{
	if (errorcode == 0)
		return ("");
	else if (errorcode == E_MLX_INIT)
		return ("mlx initialization error");
	else if (errorcode == E_MALLOC)
		return ("malloc error");
	else if (errorcode == E_SET_TYPE)
		return ("invalid set type");
	else if (errorcode == E_RES_INP)
		return ("invalid resolution format");
	else if (errorcode == E_RES_LIM)
		return ("exceeding the limits of acceptable resolution values");
	else if (errorcode == E_CNT_INP)
		return ("invalid complex format for -c param");
	else if (errorcode == E_UNREC_OPT)
		return ("unrecognized option");
	else if (errorcode == E_REQ_LIM)
		return ("recursion depth cannot be negative");

	else if (errorcode == K_CLOSED)
		return ("window closed");

	else if (errorcode == PARAM_INFO)
		return ("Try " TERM_WHITE "'./Fract-ol " WARNING "--help" TERM_WHITE
			"'" RESET " for more information");

	return (strerror(errorcode));
}
