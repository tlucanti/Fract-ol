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
#include "error.h"

#include <stdlib.h>

int	ft_close_window(void)
{
	t_data	*data;

	data = get_data();
	gui_destroy(&data->window);
	ft_ok("fract-ol", K_CLOSED, "successfully");
	ft_exit(EXIT_SUCCESS);
}
