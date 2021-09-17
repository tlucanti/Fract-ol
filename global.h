/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:52:51 by kostya            #+#    #+#             */
/*   Updated: 2021/09/17 17:42:41 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

#define NULL ((void *)0)
#define FLOAT long double

typedef struct s_params
{
	char			set;
	FLOAT			center_real;
	FLOAT			center_imag;
	FLOAT			width;
	FLOAT			out_radius_sq;
	FLOAT			c_real;
	FLOAT			c_imag;
	unsigned int	recursion_depth;
}	t_params;

typedef struct s_img
{
	void		*img;
	unsigned	*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	unsigned int	res_x;
	unsigned int	res_y;
	t_img		*img;
	t_params	*params;
}	t_data;

t_data *get_data(void);

#endif
