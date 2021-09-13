/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:52:51 by kostya            #+#    #+#             */
/*   Updated: 2021/09/13 22:38:20 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

#define NULL ((void *)0)
#ifdef FLOAT
# define FLOAT lol
#endif
#ifndef FLOAT
# define FLOAT long double
#endif

typedef struct s_params
{
	FLOAT			center_real;
	FLOAT			center_imag;
	FLOAT			width;
	FLOAT			out_radius_sq;
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
	t_img		*img;
	char		*test;
	t_params	*params;
}	t_data;

t_data *get_data(void);

#endif
