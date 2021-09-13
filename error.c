/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:34:33 by kostya            #+#    #+#             */
/*   Updated: 2021/09/13 17:11:32 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "color.h"

static const char	*ft_strerror(int errorcode);

void	ft_message(const char *type, const char *parent, int errorcode, char *message)
{
	const char	*type_chr;

	if ((void *)type == (void *)ERROR)
		type_chr = "FAIL";
	else if ((void *)type == (void *)WARNING)
		type_chr = "WARN";
	else if ((void *)type == (void *)OK)
		type_chr = " OK ";
	printf("%s[%s]%s %s: %s", type, type_chr, RESET, parent, ft_strerror(errorcode));
	if (message)
		printf(" %s%s%s\n", WARNING, message, RESET);
	else
		printf("\n");
}

inline void	ft_perror(const char *parent, int errorcode, char *message)
{
	ft_message(ERROR, parent, errorcode, message);
}

inline void	ft_warning(const char *parent, int errorcode, char *message)
{
	ft_message(WARNING, parent, errorcode, message);
}

inline void	ft_info(const char *parent, int errorcode, char *message)
{
	ft_message(INFO, parent, errorcode, message);
}

inline void	ft_ok(const char *parent, int errorcode, char *message)
{
	ft_message(OK, parent, errorcode, message);
}

void	ft_exit(int status)
{
	exit(status);
}

inline void	ft_perror_exit(const char *parent, int errorcode, char *message, int status)
{
	ft_perror(parent, errorcode, message);
	ft_exit(status);
}

static const char	*ft_strerror(int errorcode)
{
	if (errorcode == E_MLX_INIT)
		return ("mlx initialization error");
	else if (errorcode == E_MALLOC)
		return ("malloc error");


	else if (errorcode == K_CLOSED)
		return ("window closed");
	return (strerror(errorcode));
}
