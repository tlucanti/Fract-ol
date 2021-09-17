/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:54:35 by kostya            #+#    #+#             */
/*   Updated: 2021/09/17 22:53:39 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

#include <math.h>
#include "mlxlinux/mlx.h"
#include "global.h"

int		main();
void	ft_mlx_init(t_data *data);
int		mandelbrot_1(t_params *params, const FLOAT *field_real, const FLOAT *field_imag);
int		julia_1(t_params *params, const FLOAT * restrict field_real, const FLOAT * restrict field_imag);
int		palette(FLOAT intensity);
int		ft_atodl_complex(const char *str, FLOAT *real, FLOAT *imag);
FLOAT 	ft_atodl(const char *str);
int		ft_atoi_double(const char *str, int *i1, int *i2);

# define WINDOW		"Fract-ol"

# define GRADIENT_D	2
# define GRADIENT_K 4

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
# define ft_strlen strlen
# define ft_memcpy memcpy
# define ft_memcmp memcmp
# define ft_calloc calloc
# define ft_atoi(n) strtol((n), NULL, 10)
# define ft_isalnum isalnum
# define ft_isdigit isdigit
# define ft_isalpha isalpha
# define ft_isspace isspace
# define ft_strcmp strcmp

#endif
