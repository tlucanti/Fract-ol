/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:40:11 by kostya            #+#    #+#             */
/*   Updated: 2021/09/17 23:40:37 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "fract-ol.h"

static FLOAT	ft_atod_noexp(const char **str, FLOAT *sgn);
static FLOAT	ft_powd_fast(FLOAT n, int exp);
static FLOAT	ft_atod_frac(const char **str__);

int		ft_atodl_complex(const char *str, FLOAT *real, FLOAT *imag)
{
	int	__im;

	__im = 0;
	*real = ft_atodl(str);
	while (*str && *str != '+')
		++str;
	if (str[-1] == 'i')
	{
		*imag = *real;
		__im = 1;
	}
	if (!*str)
		return (1);
	if (__im)
		*real = ft_atodl(str + 1);
	else
		*imag = ft_atodl(str + 1);
	while (*str)
		++str;
	if ((str[-1] == 'i' && __im) || (str[-1] != 'i' && !__im))
		return (1);
	return (0);
}

FLOAT 	ft_atodl(const char *str)
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
	FLOAT	nn;

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
	char	*ptr;
	char	*str;
	FLOAT	ans;

	ans = 0;
	ptr = *((char **)str__);
	str = ptr;
	while (*ptr && *ptr != 'e' && *ptr != 'E')
		ptr++;
	*str__ = ptr;
	ptr-=2;
	while (str != ptr)
	{
		ans = ans * (FLOAT)0.1 + (FLOAT)(*ptr-- - 48);
	}
	return (ans * (FLOAT)0.1);
}
