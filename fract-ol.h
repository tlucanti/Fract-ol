/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:54:35 by kostya            #+#    #+#             */
/*   Updated: 2021/09/13 23:00:21 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

#include <math.h>
#include "mlxlinux/mlx.h"
#include "global.h"

int		main();
void	ft_mlx_init(t_data **data);
int		mandelbrot_1(t_params *params, FLOAT *field_real, FLOAT *field_imag);
int	palette(FLOAT intencity);

# define RES_X		800
# define RES_Y		600
# define WINDOW		"Fract-ol"

# define GRADIENT_D	2
# define GRADIENT_K 4

#endif
