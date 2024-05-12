/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_pool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:59:38 by kostya            #+#    #+#             */
/*   Updated: 2021/10/02 17:28:47 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fract_ol.h"
#include "global.h"
#include "color.h"

static int	__recursive_color_compute_newton_pool_extension(
		const t_params *restrict params, FLOAT real,
		FLOAT imag) __attribute__((warn_unused_result));

int	newton_pool(const FLOAT *restrict field_real,
	const FLOAT *restrict field_imag, t_data *restrict data)
{
	register FLOAT	real;
	register FLOAT	imag;
	unsigned short	x;
	unsigned short	y;

	y = 0;
	while (y < data->res_y)
	{
		x = 0;
		while (x < data->res_x)
		{
			real = field_real[x];
			imag = field_imag[y];
			put_pixel(data, x, y,
				__recursive_color_compute_newton_pool_extension(data->params,
					real, imag));
			++x;
		}
		++y;
	}
	return (0);
}

int	palette6(FLOAT intensity, FLOAT re, FLOAT im)
{
	int	root;
	int	req;

	req = (int)((1 - intensity) * 255);
	if (re > 0)
		root = (int)(atan2(im, re) / PI_FIFTH);
	else if (im > 0)
		root = (int)((PI_HALF + atan2(im, -re)) / PI_FIFTH);
	else
		root = (int)((PI_HALF + atan2(im, re)) / -PI_FIFTH);
	if (root == 0)
		return (req << 16u);
	else if (root == 1 || root == 2)
		return (req << 8u);
	else if (root == 3 || root == 4)
		return (req);
	else if (root == -3 || root == -4)
		return (req << 16u | req << 8u);
	else if (root == -1 || root == -2)
		return (req << 16u | req);
	else
		return (BLACK);
}

static inline int	__recursive_color_compute_newton_pool_extension(
	const t_params *restrict params, FLOAT real, FLOAT imag)
{
	unsigned short	req;
	FLOAT	d[3];
	register FLOAT	real_new;
	register FLOAT	imag_new;
	register FLOAT	abs;

	req = 0;
	abs = 0;
	while (req < params->recursion_depth)
	{
		d[0] = real * real - imag * imag;
		d[1] = 2 * real * imag;
		d[2] = powl(real * real + imag * imag, -4);
		real_new = 0.8 * real + 0.2 * d[2] * (d[0] * d[0] - d[1] * d[1]);
		imag_new = 0.8 * imag - 0.4 * d[2] * d[1] * d[0];
		abs = (real - real_new) * (real - real_new) + (imag - imag_new)
			* (imag - imag_new);
		if (abs < EPS)
			return (params->palette(req / (FLOAT)params->recursion_depth,
					real_new, imag_new));
		real = real_new;
		imag = imag_new;
		++req;
	}
	return ((int)abs);
}
