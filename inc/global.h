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

#ifndef FLOAT
# define FLOAT long double
#endif

# define ONE_SIXTH	(1.0L / 6.0L)
# define ONE_NINETH	(1.0L / 9.0L)

# include <guilib.h>

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
	int		(*palette)(FLOAT, FLOAT, FLOAT);
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
