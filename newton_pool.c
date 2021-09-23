/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_pool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:59:38 by kostya            #+#    #+#             */
/*   Updated: 2021/09/23 14:56:10 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "global.h"
#include <math.h>
#include "color.h"
#include <stdio.h>
#include <complex.h>

int	palette2(FLOAT intensity, FLOAT re,
		FLOAT im) __attribute__((warn_unused_result));
int	__recursive_color_compute_newton_pool_extension(
		const t_params *restrict params, FLOAT real,
		FLOAT imag) __attribute__((warn_unused_result));

int	newton_pool(const FLOAT *restrict field_real,
	const FLOAT *restrict field_imag, const t_data *restrict data)
{
	register FLOAT	real;
	register FLOAT	imag;
	unsigned short	x;
	unsigned short	y;

	x = 0;
	while (x < data->res_x)
	{
		y = 0;
		while (y < data->res_y)
		{
			real = field_real[x];
			imag = field_imag[y];
			put_pixel(data, x, y,
				__recursive_color_compute_newton_pool_extension(data->params,
					real, imag));
			++y;
		}
		++x;
	}
	return (0);
}

int	palette2(FLOAT intensity, FLOAT re, FLOAT im)
{
	int	root;
	int	req;

	req = (1 - intensity) * 255;
	if (re > 0)
		root = atanl(im / re) / PI_FIFTH;
	else if (im > 0)
		root = (PI_HALF + atanl(im / -re)) / PI_FIFTH;
	else
		root = (PI_HALF + atanl(im / re)) / -PI_FIFTH;
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
		return (WHITE);
}

inline int	__recursive_color_compute_newton_pool_extension(
	const t_params *restrict params, FLOAT real, FLOAT imag)
{
	unsigned short	req;
	register FLOAT	dms[3];
	register FLOAT	real_new;
	register FLOAT	imag_new;
	register FLOAT	abs;

	req = 0 || (abs = 0);
	while (req < params->recursion_depth)
	{
		dms[0] = real * real - imag * imag;
		dms[1] = 2 * real * imag;
		dms[2] = powl(real * real + imag * imag, -4);
		real_new = 0.8 * real + 0.2 * dms[2] * (dms[0] * dms[0] - dms[1]
				* dms[1]);
		imag_new = 0.8 * imag - 0.4 * dms[2] * dms[1] * dms[0];
		abs = (real - real_new) * (real - real_new) + (imag - imag_new)
			* (imag - imag_new);
		if (abs < EPS)
			return (params->palette(req / (FLOAT)params->recursion_depth,
					real_new, imag_new));
		real = real_new;
		imag = imag_new;
		++req;
	}
	return (abs);
}