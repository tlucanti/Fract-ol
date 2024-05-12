/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:36:14 by kostya            #+#    #+#             */
/*   Updated: 2021/10/02 19:13:00 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "global.h"
#include "fract_ol.h"
#include "color.h"

#include <stdio.h>

static void	print_info(const t_data *restrict data);
static int		__ft_button_press_extension_1(int key_code, t_data *restrict data);
static int		__ft_button_press_extension_2(int key_code, t_data *restrict data);

int	ft_mouse_press(int key_code, int mouse_x, int mouse_y)
{
	t_data	*data;
	FLOAT	x;
	FLOAT	y;

	data = get_data();
	//mouse_y = data->res_y * MOUSE_CORRECT + mouse_y;
	x = data->params->center_real + data->params->width
		/ (FLOAT)data->res_x * (mouse_x - (FLOAT)data->res_x / 2);
	y = data->params->center_imag + data->params->width
		* ((FLOAT)data->res_y / (FLOAT)data->res_x) / (FLOAT)data->res_y
		* (mouse_y - (FLOAT)data->res_y / 2);
	if (key_code == SCROLL_UP)
	{
		data->params->center_imag = y - (y - data->params->center_imag) * SCALE;
		data->params->center_real = x - (x - data->params->center_real) * SCALE;
		data->params->width *= SCALE;
	}
	else if (key_code == SCROLL_DOWN)
	{
		data->params->center_real = x - (x - data->params->center_real) / SCALE;
		data->params->center_imag = y - (y - data->params->center_imag) / SCALE;
		data->params->width /= SCALE;
	}
	return (0);
}

int	ft_button_press(int key_code, __attribute__((unused)) void *__d)
{
	t_data	*restrict data;

	data = get_data();
	if (key_code == KEY_X)
		ft_close_window();
	else if (key_code == KEY_NUM_UP || (key_code == KEY_W && !gui_pressed(data->window, KEY_LSHIFT)))
		data->params->center_imag -= data->params->width * KEY_SPEED;
	else if (key_code == KEY_NUM_DOWN || (key_code == KEY_S && !gui_pressed(data->window, KEY_LSHIFT)))
		data->params->center_imag += data->params->width * KEY_SPEED;
	else if (key_code == KEY_NUM_RIGHT || (key_code == KEY_D && !gui_pressed(data->window, KEY_LSHIFT)))
		data->params->center_real += data->params->width * KEY_SPEED;
	else if (key_code == KEY_NUM_LEFT || (key_code == KEY_A && !gui_pressed(data->window, KEY_LSHIFT)))
		data->params->center_real -= data->params->width * KEY_SPEED;
	else if (key_code == KEY_UP)
		data->params->recursion_depth = (unsigned int)(data->params
				->recursion_depth * SCALE) + 1;
	else if (key_code == KEY_DOWN)
		data->params->recursion_depth = (unsigned int)(data->params
				->recursion_depth / SCALE);
	else
		return (__ft_button_press_extension_1(key_code, data));
	return (0);
}

static inline int	__ft_button_press_extension_1(int key_code, t_data *restrict data)
{
	if (key_code == KEY_I)
	{
		print_info(data);
		return (0);
	}
	else if (key_code == KEY_W && gui_pressed(data->window, KEY_LSHIFT))
		data->params->c_imag *= 1.1;
	else if (key_code == KEY_S && gui_pressed(data->window, KEY_LSHIFT))
		data->params->c_imag /= 1.1;
	else if (key_code == KEY_D && gui_pressed(data->window, KEY_LSHIFT))
		data->params->c_real *= 1.002;
	else if (key_code == KEY_A && gui_pressed(data->window, KEY_LSHIFT))
		data->params->c_real /= 1.002;
	else if (key_code == KEY_EQUAL)
		ft_mouse_press(SCROLL_DOWN, (int)data->res_x / 2, (int)data->res_y / 2);
	else if (key_code == KEY_MINUS)
		ft_mouse_press(SCROLL_UP, (int)data->res_x / 2, (int)data->res_y / 2);
	else if (key_code == KEY_P)
		screenshot(data);
	else
		return (__ft_button_press_extension_2(key_code, data));
	return (0);
}

static inline int	__ft_button_press_extension_2(int key_code, t_data *restrict data)
{
	if (key_code == KEY_RIGHT)
		swap_palette_forw(data);
	else if (key_code == KEY_LEFT)
		swap_palette_backw(data);
	else
		return (0);
	return (0);
}

static inline void	print_info(const t_data *restrict data)
{
	printf(
		INFO "[INFO] " TERM_WHITE " fract-ol: " WARNING "IMAGE PARAMETERS\r\n"
		OK "  point " WARNING "> " INFO "%Lg%+Lgi\r\n"
		OK "  width " WARNING "> " INFO "%Lg\r\n"
		OK "  iter " WARNING " > " INFO "%d" RESET" \r\n",
		(long double)data->params->center_real,
		(long double)data->params->center_imag,
		(long double)data->params->width,
		data->params->recursion_depth
		);
	printf(
		INFO "[INFO] " TERM_WHITE "parameters by command:\r\n"
		"\t" OK "./Fract-ol " ERROR "%c " WARNING "-c" TERM_CYAN
		"%.16Lg%+.16Lgi" WARNING " -w" TERM_CYAN "%.16Lg" WARNING " -d"
		TERM_CYAN "%d" WARNING " -p" TERM_CYAN "%.16Lg%+.16Lgi" WARNING " -R"
		TERM_CYAN "%d%+d" RESET "\r\n", data->params->set,
		(long double)data->params->center_real,
		(long double)data->params->center_imag,
		(long double)data->params->width, data->params->recursion_depth,
		(long double)data->params->c_real, (long double)data->params->c_imag,
		data->res_x, data->res_y
		);
}
