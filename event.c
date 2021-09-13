/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:36:14 by kostya            #+#    #+#             */
/*   Updated: 2021/09/13 22:58:38 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "error.h"
#include "global.h"
#include "fract-ol.h"

#include "time.h"

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

	data = get_data();
	// if (key_code == 1)
	// {
		data->params->center_real += ((FLOAT)mouse_x / RES_X - 0.5) * data->params->width / 2;
		data->params->center_imag += ((FLOAT)mouse_y / RES_Y - 0.5) * data->params->width / 2;
	// }
	if (key_code == 4)
	{
		data->params->width *= 0.8;
	}
	else if (key_code == 5)
	{
		data->params->width *= 1.2;
	}
	time_start();
	draw_image();
	printf("point(%#8Lg, %8Lg), width(%8Lg), time(%8g)\n",
		data->params->center_real, data->params->center_imag,
		data->params->width, time_stop());
	return (0);
}

int	ft_button_press(int key_code, void *__d)
{
	(void)__d;
	if (key_code == 65307)
		ft_close_window(0, NULL);
	return (0);
}
