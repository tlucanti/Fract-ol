/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:54:35 by kostya            #+#    #+#             */
/*   Updated: 2021/10/02 17:55:54 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../inc/global.h"

int		main(int argc, const char **argv);
void	ft_mlx_init(t_data *restrict data);
int		mandelbrot_1(const FLOAT *restrict field_real,
			const FLOAT *restrict field_imag, t_data *restrict data);
int		julia_1(const FLOAT *restrict field_real,
			const FLOAT *restrict field_imag, t_data *restrict data);
int		newton_pool(const FLOAT *restrict field_real,
			const FLOAT *restrict field_imag, t_data *restrict data);
int		palette1(FLOAT intensity) __attribute__((warn_unused_result));
int		palette2(FLOAT intensity) __attribute__((warn_unused_result));
int		palette3(FLOAT intensity) __attribute__((warn_unused_result));
int		palette4(FLOAT intensity) __attribute__((warn_unused_result));
int		palette5(FLOAT intensity) __attribute__((warn_unused_result));
int		palette6(FLOAT intensity, FLOAT re,
			FLOAT im) __attribute__((warn_unused_result));
void	swap_palette_forw(const t_data *restrict data);
void	swap_palette_backw(const t_data *restrict data);
int		ft_atodl_complex(const char *restrict str, FLOAT *real, FLOAT *imag);
FLOAT	ft_atodl(const char *restrict str);
char	*str2double(const char *str,
			FLOAT *number) __attribute__((warn_unused_result));
int		ft_atoi_double(const char *restrict str, int *i1, int *i2);
int		ft_isspace(int __c) __attribute__((warn_unused_result));
int		ft_isdigit(int __c) __attribute__((warn_unused_result));
int		ft_memcmp(const void *s1, const void *s2, size_t len);
int		ft_atoi(const char *restrict str) __attribute__((warn_unused_result));
void	put_pixel(t_data *restrict data, int x, int y, unsigned int col);
void	set_options(const char **argv, t_data *restrict data,
			t_params *restrict params);
int		screenshot(const t_data *restrict data);
void	*ft_memset(void *s, int c, size_t len);

# define GRADIENT_D		2
# define GRADIENT_K		4
# define RV_LOG_2		1.4426950408889634
# define EPS			0.01
# define PI_FIFTH		(M_PI / 5.0L)
# define PI_HALF		(M_PI / 2.0L)

#endif
