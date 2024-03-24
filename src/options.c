/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 23:37:52 by kostya            #+#    #+#             */
/*   Updated: 2021/10/02 18:04:37 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "error.h"

void	__set_options_extension_1(const char *restrict argv,
			t_params *restrict params, t_data *restrict data);
void	__set_options_extension_2(const char *restrict argv,
			t_params *restrict params);
void	__set_options_extension_3(t_params *restrict params);
void	__set_options_extension_4(const char *restrict argv,
			t_params *restrict params);

void	set_options(const char **restrict argv, t_data *restrict data,
	t_params *restrict params)
{
	if (!*argv)
		ft_info_exit("fract-ol", E_SET_TYPE, "set not chose");
	if (!ft_memcmp(*argv, "--help", 7))
		print_help_message();
	if (!ft_memcmp(*argv, "mandelbrot", 11) || !ft_memcmp(*argv, "m", 2))
		params->set = 'm';
	else if (!ft_memcmp(*argv, "julia", 6) || !ft_memcmp(*argv, "j", 2))
		params->set = 'j';
	else if (!ft_memcmp(*argv, "newton", 7) || !ft_memcmp(*argv, "pool", 5)
		|| !ft_memcmp(*argv, "n", 2))
		params->set = 'n';
	else
		ft_info_exit("fract-ol", E_SET_TYPE, *argv);
	if (params->set == 'm')
		params->center_real = (FLOAT) - 0.5;
	else if (params->set == 'j' || params->set == 'n')
		params->center_real = (FLOAT)0;
	data->res_x = 800;
	data->res_y = 600;
	__set_options_extension_3(params);
	if (params->set == 'n')
		params->palette = (int (*)(FLOAT, ...)) palette6;
	while (*(++argv))
		__set_options_extension_1(*argv, params, data);
}

inline void	__set_options_extension_1(const char *restrict argv,
	t_params *restrict params, t_data *restrict data)
{
	if (!ft_memcmp(argv, "-R", 2))
	{
		if (ft_atoi_double(argv + 2, (int *)&data->res_x, (int *)&data->res_y))
			ft_info_exit("fract-ol", E_RES_INP, argv + 2);
	}
	else if (!ft_memcmp(argv, "-c", 2))
	{
		if (ft_atodl_complex(argv + 2, &params->center_real,
				&params->center_imag))
			ft_info_exit("fract-ol", E_CNT_INP, argv + 2);
	}
	else if (!ft_memcmp(argv, "-w", 2))
		params->width = ft_atodl(argv + 2);
	else if (!ft_memcmp(argv, "-r", 2))
		params->out_radius_sq = ft_atodl(argv + 2);
	else
		__set_options_extension_2(argv, params);
}

inline void	__set_options_extension_2(const char *restrict argv,
	t_params *restrict params)
{
	if (!ft_memcmp(argv, "-p", 2))
	{
		if (ft_atodl_complex(argv + 2, &params->c_real, &params->c_imag))
			ft_info_exit("fract-ol", E_CNT_INP, argv + 2);
	}
	else if (!ft_memcmp(argv, "-d", 2))
	{
		params->recursion_depth = ft_atoi(argv + 2);
		if ((int)params->recursion_depth < 0)
			ft_info_exit("fract-ol", E_REQ_LIM, argv + 2);
	}
	else if (!ft_memcmp(argv, "-s", 2))
		__set_options_extension_4(argv, params);
	else
		ft_info_exit("fract-ol", E_UNREC_OPT, argv);
}

inline void	__set_options_extension_3(t_params *restrict params)
{
	params->center_imag = 0;
	params->width = 3;
	params->out_radius_sq = 30;
	params->c_real = (FLOAT) - 0.7436447860;
	params->c_imag = (FLOAT)0.131825253;
	params->recursion_depth = 50 + 250 * (params->set == 'j')
		+ 50 * (params->set == 'n');
	params->palette = (int (*)(FLOAT, ...)) palette1;
}

inline void	__set_options_extension_4(const char *restrict argv,
	t_params *restrict params)
{
	if (argv[3] != 0)
		ft_info_exit("fract-ol", E_SCHEME_INP, argv + 2);
	else if (argv[2] == '1' && !argv[3])
		params->palette = (int (*)(FLOAT, ...)) palette1;
	else if (argv[2] == '2' && !argv[3])
		params->palette = (int (*)(FLOAT, ...)) palette2;
	else if (argv[2] == '3' && !argv[3])
		params->palette = (int (*)(FLOAT, ...)) palette3;
	else if (argv[2] == '4' && !argv[3])
		params->palette = (int (*)(FLOAT, ...)) palette4;
	else if (argv[2] == '5' && !argv[3])
		params->palette = (int (*)(FLOAT, ...)) palette5;
	else if (argv[2] == '6' && !argv[3] && params->set == 'n')
		params->palette = (int (*)(FLOAT, ...)) palette6;
	else if (params->set == 'm')
		ft_warning("fract-ol", W_SHEME_M, "defaulting to 1");
	else if (params->set == 'j')
		ft_warning("fract-ol", W_SHEME_J, "defaulting to 1");
	else
		ft_warning("fract-ol", W_SHEME_N, "defaulting to 6");
}
