/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:52:53 by kostya            #+#    #+#             */
/*   Updated: 2021/09/22 20:42:33 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "memory.h"

int	ft_atoi_double(const char *restrict str, int *i1, int *i2)
{
	if (*str == '+')
		return (1);
	*i1 = ft_atoi(str);
	while (*str && *str != '+')
		++str;
	if (!*str)
		return (1);
	*i2 = ft_atoi(str + 1);
	while (*str)
		++str;
	if (str[-1] == '+')
		return (1);
	return (0);
}

t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (!data)
		data = xmalloc(sizeof(t_data));
	return (data);
}

inline void	put_pixel(const t_data *restrict data, int x, int y,
	unsigned int col)
{
	data->img->addr[y *(data->img->line_length >> 2u) + x] = col;
}

inline int	ft_isspace(int __c)
{
	return (__c == ' ' || __c == '\t' || __c == '\n'
		|| __c == '\v' || __c == '\f' || __c == '\r');
}

inline int	ft_isdigit(int __c)
{
	return (__c >= '0' && __c <= '9');
}
