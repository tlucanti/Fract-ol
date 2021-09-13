/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:50:09 by kostya            #+#    #+#             */
/*   Updated: 2021/09/13 23:09:54 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include "global.h"
#include "memory.h"
#include "event.h"
#include "error.h"

int	main()
{
	t_params	*params;
	t_data		*data;

	params = xmalloc(sizeof(t_params));
	params->center_real = (FLOAT)-0.5;
	params->center_imag = (FLOAT)0;
	params->width = (FLOAT)3;
	params->out_radius_sq = 4 * 4;
	params->recursion_depth = 100;
	data = get_data();
	data->params = params;
	mlx_loop(data->mlx);
}

void	draw_image()
{
	FLOAT			field_real[RES_X];
	FLOAT			field_imag[RES_Y];
	FLOAT			step;
	t_data			*data;
	unsigned int	i;

	data = get_data();
	step = data->params->width / RES_X;
	field_real[0] = data->params->center_real - data->params->width / 2;
	i = 1;
	while (i < RES_X)
	{
		field_real[i] = field_real[i - 1] + step;
		++i;
	}
	i = 1;
	step = data->params->width / RES_X;
	field_imag[0] = data->params->center_imag - data->params->width * RES_Y / RES_X / 2;
	while (i < RES_Y)
	{
		field_imag[i] = field_imag[i - 1] + step;
		++i;
	}
	mandelbrot_1(data->params, field_real, field_imag);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
}

void	put_pixel(t_data *data, int x, int y, unsigned int col)
{
	data->img->addr[y *(data->img->line_length >> 2u) + x] = col;
}

int	mandelbrot_1(t_params *params, FLOAT * restrict field_real, FLOAT * restrict field_imag)
{
	register FLOAT	real;
	register FLOAT	imag;
	register FLOAT	real_sq;
	register FLOAT	imag_sq;
	register FLOAT	abs = 0;
	t_data	*data;

	data = get_data();
	for (int x=0; x < RES_X; ++x)
	{
		for (int y=0; y < RES_Y; ++y)
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
					FLOAT log_zn = log(abs) / 2;
					FLOAT nu = log(log_zn / log(2)) / log(2);
					FLOAT intencity = req + 1 - nu;
					// intencity = ((FLOAT)0.5 + 255 * (intencity) / params->recursion_depth);
					put_pixel(data, x, y, palette(intencity / params->recursion_depth));
					break;
				}
			}
			if (abs < params->out_radius_sq)
				put_pixel(data, x, y, (int)(abs * 255));
		}
	}
	return (0);
}

void	ft_mlx_init(t_data **data)
{
	*data = xmalloc(sizeof(t_data));
	(*data)->test = "test string";
	(*data)->mlx = mlx_init();
	if (!(*data)->mlx)
		ft_perror_exit("fract-ol", E_MLX_INIT, NULL, EXIT_FAILURE);
	(*data)->mlx_win = mlx_new_window((*data)->mlx, RES_X, RES_Y, WINDOW);
	if (!(*data)->mlx_win)
		ft_perror_exit("fract-ol", E_MLX_INIT, NULL, EXIT_FAILURE);
	(*data)->img = xmalloc(sizeof(t_img));
	(*data)->img->img = mlx_new_image((*data)->mlx, RES_X, RES_Y);
	if (!(*data)->img->img)
		ft_perror_exit("fract-ol", E_MLX_INIT, NULL, EXIT_FAILURE);
	(*data)->img->addr = (unsigned *)mlx_get_data_addr((*data)->img->img, &(*data)->img
		->bits_per_pixel, &(*data)->img->line_length, &(*data)->img->endian);
	mlx_put_image_to_window((*data)->mlx, (*data)->mlx_win, (*data)->img->img, 0, 0);
	mlx_hook((*data)->mlx_win, 33, 0, ft_close_window, NULL);
	mlx_hook((*data)->mlx_win, 04, (1L<<2), ft_mouse_press, NULL);
	mlx_key_hook((*data)->mlx_win, ft_button_press, NULL);
}

t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (!data)
		ft_mlx_init(&data);
	return (data);
}

int	palette(FLOAT intencity)
{
	int		out = 0;
	int		r, g, b;
	if (intencity < 0.2)
	{
		r = intencity * (32/0.2);
		g = intencity * (107 - 7)/0.2 + 7;
		b = intencity * (203 - 100)/0.2 + 100;
	}

	else if (intencity < 0.4)
	{
		r = (intencity - 0.2) * (237 - 32)/0.2 + 32;
		g = (intencity - 0.2) * (255 - 107)/0.2 + 107;
		b = (intencity - 0.2) * (255 - 203)/0.2 + 203;
	}


	else if (intencity < 0.6)
	{
		r = (intencity - 0.4) * (255 - 237)/0.2 + 237;
		g = (intencity - 0.4) * (170 - 255)/0.2 + 255;
		b = (intencity - 0.4) * (-255)/0.2 + 255;
	}


	else if (intencity < 0.8)
	{
		r = (intencity - 0.6) * (-255)/0.2 + 255;
		g = (intencity - 0.6) * (2 - 170)/0.2 + 170;
		b = 0;
	}

	else if (intencity < 1)
	{
		r = 0;
		g = (intencity - 0.8) * (7 - 2)/0.2 + 2;
		b = (intencity - 0.8) * (100)/0.2;
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
