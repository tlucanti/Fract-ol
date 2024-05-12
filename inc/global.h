/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:52:51 by kostya            #+#    #+#             */
/*   Updated: 2021/12/01 13:07:05 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# define FLOAT long double

# define ONE_SIXTH	0.16666666666666666L
# define ONE_NINETH	0.11111111111111111L

# include <guilib.h>

typedef FLOAT	t_float;

typedef struct s_params
{
	char		set;
	FLOAT		center_real;
	FLOAT		center_imag;
	FLOAT		width;
	FLOAT		out_radius_sq;
	FLOAT		c_real;
	FLOAT		c_imag;
	unsigned int	recursion_depth;
	int		(*palette)(t_float, ...);
}	t_params;

typedef struct s_data
{
	struct gui_window	*window;
	unsigned int		res_x;
	unsigned int		res_y;
	t_params		*params;
}	t_data;

t_data	*get_data(void) __attribute__((warn_unused_result));

#endif
