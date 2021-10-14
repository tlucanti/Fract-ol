/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:02:31 by kostya            #+#    #+#             */
/*   Updated: 2021/10/02 18:05:18 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "error.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int	ft_atoi(const char *restrict str)
{
	long long	ans;
	long long	sign;

	if (str == NULL)
		return (0);
	ans = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		ans = ans * 10 + (*str++ - 48);
	return ((int)(ans * sign));
}

int	screenshot(const t_data *restrict data)
{
	int					fd;
	unsigned long long	f_size;
	unsigned long long	header[7];
	size_t				_;

	fd = open("./scr.bmp", O_WRONLY | O_CREAT, 0644);
	printf("screen 2\n");
	if (fd == -1)
	{
		ft_perror("fract-ol", E_SCREENSHOT, strerror(errno));
		return (1);
	}
	ft_memset(header, 0, 56);
	f_size = 14 + 40 + (data->res_x * data->res_y) * 4;
	header[0x00] = 0x4d42u | f_size << 16u;
	header[0x01] = 0x28000000380000u;
	header[0x02] = (unsigned long long) data->res_x << 16u
		| ((unsigned long long)(short)data
			->res_y) << 48u;
	header[0x03] = (unsigned) data->res_y >> 16u | 0x2000010000u;
	_ = write(fd, header, 56);
	_ += write(fd, data->img->addr, data->res_x * data->res_y * 4);
	(void)_;
	close(fd);
	ft_ok("fract-ol", K_SCREENSHOT, "as ./scr.bmp");
	return (0);
}

int	ft_atodl_complex(const char *str, long double *real, long double *imag)
{
	int	__im;

	__im = 0;
	str = str2double(str, real);
	if (*str == 'i')
	{
		__im = 1;
		*imag = *real;
	}
	if (__im)
		str = str2double(str + 1, real);
	else
		str = str2double(str + 1, imag);
	if ((__im && *str == 'i') || (!__im && *str != 'i'))
		return (1);
	return (0);
}

void	swap_palette_forw(const t_data *restrict data)
{
	if ((size_t)data->params->palette == (size_t)palette1)
		data->params->palette = (int (*)(FLOAT, ...)) palette2;
	else if ((size_t)data->params->palette == (size_t)palette2)
		data->params->palette = (int (*)(FLOAT, ...)) palette3;
	else if ((size_t)data->params->palette == (size_t)palette3)
		data->params->palette = (int (*)(FLOAT, ...)) palette4;
	else if ((size_t)data->params->palette == (size_t)palette4)
		data->params->palette = (int (*)(FLOAT, ...)) palette5;
	else if ((size_t)data->params->palette == (size_t)palette5)
	{
		if (data->params->set == 'n')
			data->params->palette = (int (*)(FLOAT, ...)) palette6;
		else
			data->params->palette = (int (*)(FLOAT, ...)) palette1;
	}
	else
		data->params->palette = (int (*)(FLOAT, ...)) palette1;
}

void	swap_palette_backw(const t_data *restrict data)
{
	if ((size_t)data->params->palette == (size_t)palette1)
	{
		if (data->params->set == 'n')
			data->params->palette = (int (*)(FLOAT, ...)) palette6;
		else
			data->params->palette = (int (*)(FLOAT, ...)) palette5;
	}
	else if ((size_t)data->params->palette == (size_t)palette2)
		data->params->palette = (int (*)(FLOAT, ...)) palette1;
	else if ((size_t)data->params->palette == (size_t)palette3)
		data->params->palette = (int (*)(FLOAT, ...)) palette2;
	else if ((size_t)data->params->palette == (size_t)palette4)
		data->params->palette = (int (*)(FLOAT, ...)) palette3;
	else if ((size_t)data->params->palette == (size_t)palette5)
		data->params->palette = (int (*)(FLOAT, ...)) palette4;
	else
		data->params->palette = (int (*)(FLOAT, ...)) palette5;
}
