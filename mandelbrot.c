/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 23:35:41 by kostya            #+#    #+#             */
/*   Updated: 2021/09/23 15:43:04 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "global.h"

int	__recursive_color_compute_mandelbrot_extension(
		const t_params *restrict params, FLOAT real,
		FLOAT imag) __attribute__((warn_unused_result));

int	mandelbrot_1(const FLOAT *restrict field_real,
	const FLOAT *restrict field_imag, const t_data *restrict data)
{
	register FLOAT	real;
	register FLOAT	imag;
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < data->res_x)
	{
		y = 0;
		while (y < data->res_y)
		{
			real = field_real[x];
			imag = field_imag[y];
			put_pixel(data, (int)x, (int)y,
				__recursive_color_compute_mandelbrot_extension(data->params,
					real, imag));
			++y;
		}
		++x;
	}
	return (0);
}

inline int	__recursive_color_compute_mandelbrot_extension(
	const t_params *restrict params, FLOAT real, FLOAT imag)
{
	unsigned int	req;
	register FLOAT	real_sq;
	register FLOAT	imag_sq;
	register FLOAT	abs;
	register FLOAT	points[2];

	points[0] = real;
	points[1] = imag;
	req = 0;
	real_sq = real * real;
	imag_sq = imag * imag;
	abs = real_sq + imag_sq;
	while (req < params->recursion_depth)
	{
		imag = 2 * real * imag + points[1];
		real = real_sq - imag_sq + points[0];
		real_sq = real * real;
		imag_sq = imag * imag;
		abs = real_sq + imag_sq;
		if (abs > params->out_radius_sq)
			return (palette1((req + 1 - logl(logl(abs) * 0.5 * RV_LOG_2)
						* RV_LOG_2) / params->recursion_depth));
		++req;
	}
	return ((int)(abs * 255 / 2));
}
