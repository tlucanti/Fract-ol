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
#include "color.h"

void	__fill_draw_arrays_extension(FLOAT **restrict field_real,
			FLOAT **restrict field_imag, const t_data *restrict data);

int	main(int argc, const char **argv)
{
	t_params	params;
	t_data		*data;

	(void)argc;
	data = get_data();
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_perror_exit("fract-ol", E_MLX_INIT, NULL, EXIT_FAILURE);
	set_options(argv + 1, data, &params);
	ft_mlx_init(data);
	data->params = &params;
	mlx_string_put(data->mlx, data->mlx_win, (int)data->res_x / 2,
		(int)data->res_y / 2, WHITE, (char *)"LOADING ...");
	draw_image(0);
	mlx_loop(data->mlx);
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
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
}

inline void	__fill_draw_arrays_extension(FLOAT **restrict field_real,
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

void	ft_mlx_init(t_data *restrict data)
{
	data->mlx_win = mlx_new_window(data->mlx, (int)data->res_x,
			(int)data->res_y, WINDOW);
	if (!data->mlx_win)
		ft_perror_exit("fract-ol", E_MLX_INIT, NULL, EXIT_FAILURE);
	data->img = (t_img *)xmalloc(sizeof(t_img));
	data->img->img = mlx_new_image(data->mlx, (int)data->res_x,
			(int)data->res_y);
	if (!data->img->img)
		ft_perror_exit("fract-ol", E_MLX_INIT, NULL, EXIT_FAILURE);
	data->img->addr = (unsigned *)mlx_get_data_addr(data->img->img, &data->img
			->bits_per_pixel, &data->img->line_length, &data->img->endian);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
	mlx_hook(data->mlx_win, 33, 0, ft_close_window, NULL);
	mlx_hook(data->mlx_win, 04, 1L << 2, (int (*)())(long)ft_mouse_press, NULL);
	mlx_key_hook(data->mlx_win, (int (*)())(long)ft_button_press, NULL);
}
