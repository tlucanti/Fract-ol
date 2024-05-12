/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 23:35:41 by kostya            #+#    #+#             */
/*   Updated: 2021/10/02 17:43:46 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "global.h"

#include <math.h>
#include <pthread.h>

struct args {
	t_data *data;
	const FLOAT *restrict field_real;
	const FLOAT *restrict field_imag;
	int thread_id;
};

static int	__recursive_color_compute_mandelbrot_extension(
		const t_params *restrict params, FLOAT real,
		FLOAT imag) __attribute__((warn_unused_result));
static void *mandelbrot_worker(void *thread_id);

static struct args g_args;

int	mandelbrot_1(const FLOAT *restrict field_real,
	const FLOAT *restrict field_imag, t_data *restrict data)
{
	g_args.data = data;
	g_args.field_imag = field_imag;
	g_args.field_real = field_real;
	g_args.thread_id = 0;

#if NR_THREADS > 1
	pthread_t threads[NR_THREADS];

	for (unsigned long i = 0; i < NR_THREADS; i++) {
		pthread_create(&threads[i], NULL, mandelbrot_worker, (void *)i);
	}

	for (int i = 0; i < NR_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}
#else
	mandelbrot_worker(&args);
#endif

	return 0;
}

static void *mandelbrot_worker(void *thread_id)
{
	register FLOAT	real;
	register FLOAT	imag;
	const unsigned int	rx = g_args.data->res_x;
	const unsigned int	ry = g_args.data->res_y;

	for (unsigned y = (unsigned long)thread_id; y < ry; y += NR_THREADS) {
		for (unsigned x = 0; x < rx; x++) {
			real = g_args.field_real[x];
			imag = g_args.field_imag[y];
			put_pixel(g_args.data, (int)x, (int)y,
				__recursive_color_compute_mandelbrot_extension(g_args.data->params,
					real, imag));
		}
	}

	return NULL;
}

static inline int	__recursive_color_compute_mandelbrot_extension(
	const t_params *restrict params, FLOAT real, FLOAT imag)
{
	unsigned int	req;
	register FLOAT	real_sq;
	register FLOAT	imag_sq;
	register FLOAT	abs;
	FLOAT	points[2];

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
			return (params->palette((req + 1 - logl(logl(abs) * 0.5 * RV_LOG_2)
						* RV_LOG_2) / params->recursion_depth, 0, 0));
		++req;
	}
	return ((int)(abs * 255 / 2));
}
