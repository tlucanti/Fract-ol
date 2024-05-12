/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:50:09 by kostya            #+#    #+#             */
/*   Updated: 2021/10/02 19:36:24 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "global.h"
#include "memory.h"
#include "event.h"
#include "error.h"

#include <guilib.h>
#include <stdguilib.h>

#include <stdlib.h>

static void	__fill_draw_arrays_extension(FLOAT **restrict field_real,
			FLOAT **restrict field_imag, const t_data *restrict data);
static void callback(struct gui_window *window, int key, bool pressed);

int	main(int argc, const char **argv)
{
	t_params	params;
	t_data		*data;

	(void)argc;
	data = get_data();
	gui_bootstrap();
	if (false)
		ft_perror_exit("fract-ol", E_MLX_INIT, NULL, EXIT_FAILURE);
	set_options(argv + 1, data, &params);
        data->window = gui_alloc();
	gui_create(data->window, data->res_x, data->res_y);
	gui_key_hook(data->window, callback);

	data->params = &params;
	//mlx_string_put(data->mlx, data->mlx_win, (int)data->res_x / 2,
	//	(int)data->res_y / 2, WHITE, (char *)"LOADING ...");

	while (!gui_closed(data->window)) {
		draw_image(0);
		gui_draw(data->window);
		gui_wfi(data->window);
		// printf("fps: %f\r\n", gui_get_fps());
	}
	ft_close_window();
}

void	draw_image(int do_free)
{
	static FLOAT		*field_real = NULL;
	static FLOAT		*field_imag = NULL;
	t_data	*restrict	data;

	data = get_data();
	if (do_free)
	{
		free(field_real);
		free(field_imag);
		return ;
	}
	__fill_draw_arrays_extension(&field_real, &field_imag, data);
	if (data->params->set == 'm')
		mandelbrot_1(field_real, field_imag, data);
	else if (data->params->set == 'j')
		julia_1(field_real, field_imag, data);
	else if (data->params->set == 'n')
		newton_pool(field_real, field_imag, data);
}

static inline void	__fill_draw_arrays_extension(FLOAT **restrict field_real,
	FLOAT **restrict field_imag, const t_data *restrict data)
{
	unsigned int	i;
	register FLOAT	step;

	if (*field_real == NULL || *field_imag == NULL)
	{
		*field_real = (FLOAT *)xmalloc(sizeof(FLOAT) * data->res_x);
		*field_imag = (FLOAT *)xmalloc(sizeof(FLOAT) * data->res_y);
	}
	i = 1;
	step = data->params->width / data->res_x;
	**field_real = data->params->center_real - data->params->width / 2;
	while (i < data->res_x)
	{
		field_real[0][i] = field_real[0][i - 1] + step;
		++i;
	}
	i = 1;
	step = data->params->width / data->res_x;
	**field_imag = data->params->center_imag - data->params->width
		* data->res_y / data->res_x / 2;
	while (i < data->res_y)
	{
		field_imag[0][i] = field_imag[0][i - 1] + step;
		++i;
	}
}

static void callback(struct gui_window *window, int key, bool pressed)
{
	if (!pressed) {
		return;
	}

	if (key <= 7 || key == SCROLL_UP || key == SCROLL_DOWN) {
		int x, y;

		gui_mouse(window, &x, &y);
		ft_mouse_press(key, x, y);
	} else {
		ft_button_press(key, NULL);
	}
}
