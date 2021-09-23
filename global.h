/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:52:51 by kostya            #+#    #+#             */
/*   Updated: 2021/09/23 18:39:11 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# define THANKS_NORMINETTE_NICE_WORK_NOW_I_NEED_TO_DO_THIS_TO_FIX_MY_ERROR 0
# ifndef NULL
#  define NULL THANKS_NORMINETTE_NICE_WORK_NOW_I_NEED_TO_DO_THIS_TO_FIX_MY_ERROR
# endif
# define FLOAT long double

typedef FLOAT	t_float;

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
	int				(*palette)(t_float, ...);
}	t_params;

typedef struct s_img
{
	void			*img;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_img;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	unsigned int	res_x;
	unsigned int	res_y;
	t_img			*img;
	t_params		*params;
}	t_data;

t_data	*get_data(void) __attribute__((warn_unused_result));

#endif
