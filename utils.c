/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:52:53 by kostya            #+#    #+#             */
/*   Updated: 2021/09/17 18:09:03 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	ft_atoi_double(const char *str, int *i1, int *i2)
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
