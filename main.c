/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:50:09 by kostya            #+#    #+#             */
/*   Updated: 2021/09/17 23:58:51 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include "global.h"
#include "memory.h"
#include "event.h"
#include "error.h"

static void	put_pixel(t_data *data, int x, int y, unsigned int col);
static void	set_options(char **argv, t_data *data, t_params *params);
static void	get_options_1(char *argv, t_params *params, t_data *data);

int	main(int argc, char **argv)
{
	t_params	params;
	t_data		*data;
	// int			frac;

	(void)argc;
	// FLOAT a=0, b=0;
	// int r = ft_atodl_complex(argv[1], &a, &b);
	// if (r)
		// printf(">>> ERROR r(%d) > (%.20Lf, %.20Lf)\n", r, a, b);
	// else
		// printf("r(%d) > (%.20Lf, %.20Lf)\n", r, a, b);
// 
	// return (0);

	data = get_data();
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_perror_exit("fract-ol", E_MLX_INIT, NULL, EXIT_FAILURE);
	set_options(argv + 1, data, &params);
	ft_mlx_init(data);
	data->params = &params;
	mlx_loop(data->mlx);
	// frac = 'm';
	// if (frac == 'm')
	// {
	// 	params = (t_params){
	// 		.set = 'm',
	// 		.center_real = (FLOAT)-0.5,
	// 		.center_imag = (FLOAT)0,
	// 		.width = (FLOAT)3,
	// 		.out_radius_sq = 4 * 4,
	// 		.c_real = 0,
	// 		.c_imag = 0,
	// 		.recursion_depth = 100
	// 	};
	// }
	// else if (frac == 'j')
	// {
	// 	params = (t_params){
	// 		.set = 'j',
	// 		.center_real = (FLOAT)0,
	// 		.center_imag = (FLOAT)0,
	// 		.width = (FLOAT)3,
	// 		.out_radius_sq = 0,
	// 		// .c_real = (FLOAT)-0.74543,
	// 		// .c_imag = (FLOAT)0.11301,
	// 		.c_real = (FLOAT)0.275,
	// 		.c_imag = (FLOAT)0.01,
	// 		.recursion_depth = 500
	// 	};
	// }
}

static void	get_options_2(char *argv, t_params *params)
{
	if (!ft_memcmp(argv, "-p", 2))
	{
		if (ft_atodl_complex(argv + 2, &params->c_real, &params->c_imag))
			ft_info_exit("fract-ol", E_CNT_INP, argv + 2);
	}
	else if (!ft_memcmp(argv, "-d", 2))
	{
		params->recursion_depth = ft_atoi(argv + 2);
		if ((int)params->recursion_depth < 0)
			ft_info_exit("fract-ol", E_REQ_LIM, argv + 2);
	}
	else
		ft_info_exit("fract-ol", E_UNREC_OPT, argv);
}

static void	get_options_1(char *argv, t_params *params, t_data *data)
{
	unsigned int	max_x;
	unsigned int	max_y;

	if (!ft_memcmp(argv, "-R", 2))
	{
		if (ft_atoi_double(argv + 2, (int *)&data->res_x, (int *)&data->res_y))
			ft_info_exit("fract-ol", E_RES_INP, argv + 2);
		mlx_get_screen_size(data->mlx, (int *)&max_x, (int *)&max_y);
		if (data->res_x >= max_x || data->res_y >= max_y)
			ft_info_exit("fract-ol", E_RES_LIM, argv + 2);
	}
	else if (!ft_memcmp(argv, "-c", 2))
	{
		if (ft_atodl_complex(argv + 2, &params->center_real,
				&params->center_imag))
			ft_info_exit("fract-ol", E_CNT_INP, argv + 2);
	}
	else if (!ft_memcmp(argv, "-w", 2))
		params->width = ft_atodl(argv + 2);
	else if (!ft_memcmp(argv, "-r", 2))
		params->out_radius_sq = ft_atodl(argv + 2);
	else
		get_options_2(argv, params);
}

static void	set_options(char **argv, t_data *data, t_params *params)
{
	if (!*argv)
		ft_info_exit("fract-ol", E_SET_TYPE, "set not choosed");
	if (!ft_memcmp(*argv, "--help", 7))
		print_help_message();
	if (!ft_memcmp(*argv, "mandelbrot", 11) || !ft_memcmp(*argv, "m", 2))
		params->set = 'm';
	else if (!ft_memcmp(*argv, "julia", 6) || !ft_memcmp(*argv, "j", 2))
		params->set = 'j';
	else
		ft_info_exit("fract-ol", E_SET_TYPE, *argv);
	if (params->set == 'm')
		params->center_real = (FLOAT)-0.5;
	else if (params->set == 'j')
		params->center_real = (FLOAT)0;
	data->res_x = 800;
	data->res_y = 600;
	params->center_imag = 0;
	params->width = 3;
	params->out_radius_sq = 30;
	params->c_real = (FLOAT)-0.7436447860;
	params->c_imag = (FLOAT)0.131825253;
	params->recursion_depth = 300;
	while (*(++argv))
		get_options_1(*argv, params, data);
}

void	draw_image()
{
	static FLOAT	*field_real = NULL;
	static FLOAT	*field_imag = NULL;
	FLOAT			step;
	t_data			*data;
	unsigned int	i;

	data = get_data();
	if (field_real == NULL)
	{
		field_real = xmalloc(sizeof(FLOAT) * data->res_x);
		field_imag = xmalloc(sizeof(FLOAT) * data->res_y);
	}
	step = data->params->width / data->res_x;
	field_real[0] = data->params->center_real - data->params->width / 2;
	i = 1;
	while (i < data->res_x)
	{
		field_real[i] = field_real[i - 1] + step;
		++i;
	}
	i = 1;
	step = data->params->width / data->res_x;
	field_imag[0] = data->params->center_imag - data->params->width * data->res_y / data->res_x / 2;
	while (i < data->res_y)
	{
		field_imag[i] = field_imag[i - 1] + step;
		++i;
	}
	if (data->params->set == 'm')
	{
		mandelbrot_1(data->params, field_real, field_imag);
	}
	else if (data->params->set == 'j')
	{
		FLOAT c_r = data->params->c_real;
		FLOAT c_m = data->params->c_imag;
		data->params->out_radius_sq = (1 + sqrtl(1 + 4 * sqrtl(c_r * c_r + c_m * c_m)));
		// data->params->out_radius_sq = sqrtl(data->params->out_radius_sq);
		// data->params->out_radius_sq = 1e20;
		julia_1(data->params, field_real, field_imag);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
}

int	julia_1(t_params *params, const FLOAT * restrict field_real, const FLOAT * restrict field_imag)
{
	register FLOAT	real;
	register FLOAT	imag;
	register FLOAT	real_sq;
	register FLOAT	imag_sq;
	register FLOAT	abs = 0;
	t_data	*data;

	data = get_data();
	for (unsigned int x=0; x < data->res_x; ++x)
	{
		for (unsigned int y=0; y < data->res_y; ++y)
		{
			put_pixel(data, x, y, 0x00000000);
			real = field_real[x];
			imag = field_imag[y];
			real_sq = real * real;
			imag_sq = imag * imag;
			for (unsigned int req=0; req < params->recursion_depth; ++req)
			{
				imag = 2 * real * imag + params->c_imag;
				real = real_sq - imag_sq + params->c_real;
				real_sq = real * real;
				imag_sq = imag * imag;
				abs = real_sq + imag_sq;
				if (abs > params->out_radius_sq)
				{
					// FLOAT log_zn = log(abs) / 2;
					// FLOAT nu = log(log_zn / log(2)) / log(2);
//					FLOAT nu = 1;
					FLOAT intencity = req;
					// intencity = ((FLOAT)0.5 + 255 * (intencity) / params->recursion_depth);
					put_pixel(data, x, y, palette(intencity / params->recursion_depth));
					break;
				}
			}
			// if (abs < params->out_radius_sq)
				// put_pixel(data, x, y, (unsigned char)(abs * 255));
		}
	}
	return (0);
}

int	mandelbrot_1(t_params *params, const FLOAT * restrict field_real, const FLOAT * restrict field_imag)
{
	register FLOAT	real;
	register FLOAT	imag;
	register FLOAT	real_sq;
	register FLOAT	imag_sq;
	register FLOAT	abs = 0;
	t_data	*data;

	data = get_data();
	for (unsigned int x=0; x < data->res_x; ++x)
	{
		for (unsigned int y=0; y < data->res_y; ++y)
		{
			put_pixel(data, x, y, 0x00000000);
			real = 0;
			imag = 0;
			real_sq = 0;
			imag_sq = 0;
			for (unsigned int req=0; req < params->recursion_depth; ++req)
			{
				imag = 2 * real * imag + field_imag[y];
				real = real_sq - imag_sq + field_real[x];
				real_sq = real * real;
				imag_sq = imag * imag;
				abs = real_sq + imag_sq;
				if (abs > params->out_radius_sq)
				{
					FLOAT log_zn = logl(abs) / 2;
					FLOAT nu = logl(log_zn / log(2)) / log(2);
					FLOAT intensity = req + 1 - nu;
					// intensity = ((FLOAT)0.5 + 255 * (intensity) / params->recursion_depth);
					put_pixel(data, x, y, palette(intensity / params->recursion_depth));
					break;
				}
			}
			if (abs < params->out_radius_sq)
				put_pixel(data, x, y, (unsigned char)(abs * 255));
		}
	}
	return (0);
}

void	ft_mlx_init(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, data->res_x, data->res_y, WINDOW);
	if (!data->mlx_win)
		ft_perror_exit("fract-ol", E_MLX_INIT, NULL, EXIT_FAILURE);
	data->img = xmalloc(sizeof(t_img));
	data->img->img = mlx_new_image(data->mlx, data->res_x, data->res_y);
	if (!data->img->img)
		ft_perror_exit("fract-ol", E_MLX_INIT, NULL, EXIT_FAILURE);
	data->img->addr = (unsigned *)mlx_get_data_addr(data->img->img, &data->img
		->bits_per_pixel, &data->img->line_length, &data->img->endian);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
	mlx_hook(data->mlx_win, 33, 0, ft_close_window, NULL);
	mlx_hook(data->mlx_win, 04, (1L<<2), ft_mouse_press, NULL);
	mlx_key_hook(data->mlx_win, ft_button_press, NULL);
}

t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (!data)
		data = xmalloc(sizeof(t_data));
	return (data);
}

int	palette(FLOAT intensity)
{
	int		out = 0;
	int		r, g, b;
	if (intensity < 0.2)
	{
		r = intensity * (32 / 0.2);
		g = intensity * (107 - 7) / 0.2 + 7;
		b = intensity * (203 - 100) / 0.2 + 100;
	}

	else if (intensity < 0.4)
	{
		r = (intensity - 0.2) * (237 - 32) / 0.2 + 32;
		g = (intensity - 0.2) * (255 - 107) / 0.2 + 107;
		b = (intensity - 0.2) * (255 - 203) / 0.2 + 203;
	}


	else if (intensity < 0.6)
	{
		r = (intensity - 0.4) * (255 - 237) / 0.2 + 237;
		g = (intensity - 0.4) * (170 - 255) / 0.2 + 255;
		b = (intensity - 0.4) * (-255) / 0.2 + 255;
	}


	else if (intensity < 0.8)
	{
		r = (intensity - 0.6) * (-255) / 0.2 + 255;
		g = (intensity - 0.6) * (2 - 170) / 0.2 + 170;
		b = 0;
	}

	else if (intensity < 1)
	{
		r = 0;
		g = (intensity - 0.8) * (7 - 2) / 0.2 + 2;
		b = (intensity - 0.8) * (100) / 0.2;
	}

	else
	{
		r = 255;
		g = 255;
		b = 255;
	}

	out |= r << 16;
	out |= g << 8;
	out |= b;

	return (out);
}

static void	put_pixel(t_data *data, int x, int y, unsigned int col)
{
	data->img->addr[y *(data->img->line_length >> 2u) + x] = col;
}
