/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:36:14 by kostya            #+#    #+#             */
/*   Updated: 2021/09/18 00:00:40 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "error.h"
#include "global.h"
#include "fract-ol.h"
#include "color.h"

#include "time.h"

void	print_info(t_data *data);

int	ft_close_window(int __s, void *__d)
{
	t_data	*data;
	(void)__s;
	(void)__d;

	data = get_data();
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_ok("fract-ol", K_CLOSED, "successfuly");
	ft_exit(EXIT_SUCCESS);
}

int	ft_mouse_press(int key_code, int mouse_x, int mouse_y)
{
	t_data	*data;
	FLOAT	scale = 2; //1.2;

	data = get_data();
	FLOAT x = data->params->center_real + data->params->width / (FLOAT)data->res_x * (mouse_x - (FLOAT)data->res_x / 2);
	FLOAT y = data->params->center_imag + data->params->width * ((FLOAT)data->res_y/(FLOAT)data->res_x) / (FLOAT)data->res_y * (mouse_y - (FLOAT)data->res_y / 2);
	if (key_code == 4)
	{
		data->params->center_imag = y - (y - data->params->center_imag) * scale;
		data->params->center_real = x - (x - data->params->center_real) * scale;
		data->params->width *= scale;
	}
	else if (key_code == 5)
	{
		data->params->center_real = x - (x - data->params->center_real) / scale;
		data->params->center_imag = y - (y - data->params->center_imag) / scale;
		data->params->width /= scale;
	}
	draw_image();
	return (0);
}

int	ft_button_press(int key_code, void *__d)
{
	t_data	*data;

	time_start();
	data = get_data();
	(void)__d;
	if (key_code == KEY_ESC)
		ft_close_window(0, NULL);
	else if (key_code == NUM_UP)
		data->params->center_imag -= data->params->width * KEY_SPEED;
	else if (key_code == NUM_DOWN)
		data->params->center_imag += data->params->width * KEY_SPEED;
	else if (key_code == NUM_RIGHT)
		data->params->center_real += data->params->width * KEY_SPEED;
	else if (key_code == NUM_LEFT)
		data->params->center_real -= data->params->width * KEY_SPEED;
	else if (key_code == KEY_UP)
		data->params->recursion_depth = data->params->recursion_depth * 1.2;
	else if (key_code == KEY_DOWN)
		data->params->recursion_depth = data->params->recursion_depth / 1.2;
	else if (key_code == 105)
	{
		print_info(data);
		return (0);
	}
	draw_image();
	// printf("%d\n", key_code);
	return (0);
}

inline void	print_info(t_data *data)
{
	printf(
		INFO "[INFO] " TERM_WHITE " fract-ol: " WARNING "IMAGE PARAMETERS\n"
		OK "  point " WARNING "> " INFO "%.16Lf%+.16Lfi\n"
		OK "  width " WARNING "> " INFO "%.16Lf\n"
		OK "  iter " WARNING " > " INFO "%d\n"
		OK "  time " WARNING " > " INFO "%.4f\n" RESET,
		(long double)data->params->center_real,
		(long double)data->params->center_imag,
		(long double)data->params->width,
		data->params->recursion_depth,
		time_stop()
		);
}
