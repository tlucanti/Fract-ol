/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:06:53 by kostya            #+#    #+#             */
/*   Updated: 2021/10/02 18:50:58 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "color.h"
#include "fract_ol.h"
#include "error.h"
#include <stdio.h>

int	ft_close_window(void)
{
	t_data	*data;

	data = get_data();
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_ok("fract-ol", K_CLOSED, "successfully");
	ft_exit(EXIT_SUCCESS);
}
