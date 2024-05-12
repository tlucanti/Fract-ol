/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:40:11 by kostya            #+#    #+#             */
/*   Updated: 2021/09/23 14:39:45 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "fract_ol.h"

static FLOAT	ft_atod_noexp(const char **str,
						FLOAT *sgn) __attribute__((warn_unused_result));
static FLOAT	ft_powd_fast(FLOAT n,
						int exp) __attribute__((warn_unused_result));
static FLOAT	ft_atod_frac(
						const char **str__) __attribute__((warn_unused_result));

FLOAT	ft_atodl(const char *str)
{
	FLOAT	ans;
	FLOAT	sgn;

	if (str == NULL)
		return (0);
	while (ft_isspace(*str))
		str++;
	ans = ft_atod_noexp(&str, &sgn);
	if (*str == '.')
		ans += ft_atod_frac(&str);
	if (*str == 'e' || *str == 'E')
		return (sgn * ans * ft_powd_fast(10, ft_atoi(++str)));
	return (sgn * ans);
}

char	*str2double(const char *str, FLOAT *number)
/*
** converts [str] to FLOAT, save result in [number]
** return pointer to next symbol after end of number
*/
{
	FLOAT	ans;
	FLOAT	sgn;

	if (str == NULL)
		return (NULL);
	while (ft_isspace(*str))
		str++;
	ans = ft_atod_noexp(&str, &sgn);
	if (*str == '.')
		ans += ft_atod_frac(&str);
	if (*str == 'e' || *str == 'E')
		*number = sgn * ans * ft_powd_fast(10, ft_atoi(++str));
	else
		*number = sgn * ans;
	if (str[-1] == 'e' || str[-1] == 'E')
	{
		if (*str == '-' || *str == '+')
			++str;
		while (ft_isdigit(*str))
			++str;
	}
	return ((char *)str);
}

static FLOAT	ft_atod_noexp(const char **str, FLOAT *sgn)
{
	FLOAT	ans;

	ans = 0;
	*sgn = 1;
	if (**str == '-')
		*sgn = -1;
	if (**str == '-' || **str == '+')
		(*str)++;
	while (ft_isdigit(**str))
		ans = ans * (FLOAT)10 + (FLOAT)(*(*str)++ - 48);
	return (ans);
}

static FLOAT	ft_powd_fast(FLOAT n, int exp)
{
	FLOAT nn;

	if (exp == 0)
		return (1);
	else if (exp < 0)
		return ((FLOAT)1 / ft_powd_fast(n, -exp));
	else if (exp % 2)
		return (n * ft_powd_fast(n, exp - 1));
	else
	{
		nn = ft_powd_fast(n, exp / 2);
		return (nn * nn);
	}
}

static FLOAT	ft_atod_frac(const char **str__)
{
	char		*ptr;
	char		*str;
	FLOAT	ans;

	ans = 0;
	ptr = *((char **)str__);
	str = ptr;
	++ptr;
	while (ft_isdigit(*ptr))
		ptr++;
	*str__ = ptr;
	ptr -= 1;
	while (str != ptr)
	{
		ans = ans * (FLOAT)0.1 + (FLOAT)(*ptr-- - 48);
	}
	return (ans * (FLOAT)0.1);
}
