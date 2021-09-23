/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:34:33 by kostya            #+#    #+#             */
/*   Updated: 2021/09/22 21:27:16 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "color.h"

static const char	*ft_strerror(
						int errorcode) __attribute__((warn_unused_result));
const char			*__strerror_extension(
						int errorcode) __attribute__((warn_unused_result));

void	ft_message(unsigned int type, const char *restrict parent,
	int errorcode, const char *restrict message)
{
	const char	*type_chr;

	if (type == ERROR_TOKEN)
		type_chr = ERROR"[FAIL]";
	else if (type == WARNING_TOKEN)
		type_chr = WARNING"[WARN]";
	else if (type == OK_TOKEN)
		type_chr = OK"[ OK ]";
	else if (type == INFO_TOKEN)
		type_chr = INFO"[INFO]";
	printf("%s%s ", type_chr, RESET);
	if (parent)
		printf("%s%s:%s ", TERM_WHITE, parent, RESET);
	printf("%s", ft_strerror(errorcode));
	if (message)
		printf(": %s%s%s\n", WARNING, message, RESET);
	else
		printf("\n");
}

inline void	ft_perror_exit(const char *restrict parent, int errorcode,
	const char *restrict message, int status)
{
	ft_perror(parent, errorcode, message);
	ft_exit(status);
}

inline void	ft_info_exit(const char *restrict parent, int errorcode,
	const char *restrict message)
{
	ft_perror(parent, errorcode, message);
	ft_info("fract-ol", I_PARAM, NULL);
	ft_exit(1);
}

static const char	*ft_strerror(int errorcode)
{
	if (errorcode == 0)
		return ("");
	else if (errorcode == E_MLX_INIT)
		return ("mlx initialization error");
	else if (errorcode == E_MALLOC)
		return ("malloc error");
	else if (errorcode == E_SET_TYPE)
		return ("invalid set type");
	else if (errorcode == E_RES_INP)
		return ("invalid resolution format");
	else if (errorcode == E_RES_LIM)
		return ("exceeding the limits of acceptable resolution values");
	else if (errorcode == E_CNT_INP)
		return ("invalid complex format for -c param");
	else if (errorcode == E_UNREC_OPT)
		return ("unrecognized option");
	else if (errorcode == E_REQ_LIM)
		return ("recursion depth cannot be negative");
	else if (errorcode == E_SCHEME_INP)
		return ("invalid color sheme format");
	else if (errorcode == W_SHEME_M)
		return ("scheme is not suported for mandelbrot");
	else
		return (__strerror_extension(errorcode));
}

inline const char	*__strerror_extension(int errorcode)
{
	if (errorcode == W_SHEME_J)
		return ("scheme is not suported for julia");
	else if (errorcode == W_SHEME_N)
		return ("scheme is not suported for newton pool");
	else if (errorcode == K_CLOSED)
		return ("window closed");
	else if (errorcode == K_SCREENSHOT)
		return ("screenshot saved "TERM_GREEN"successfuly"TERM_RESET);
	else if (errorcode == I_PARAM)
		return ("Try " TERM_WHITE "'./Fract-ol " WARNING "--help" TERM_WHITE
			"'" RESET " for more information");
	return (strerror(errorcode));
}
