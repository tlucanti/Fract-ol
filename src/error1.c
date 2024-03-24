/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:29:36 by kostya            #+#    #+#             */
/*   Updated: 2021/09/23 00:03:46 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "color.h"
#include "event.h"
#include "global.h"

#include <stdlib.h>

void	ft_message(unsigned int type, const char *parent, int errorcode,
			const char *restrict message);

inline void	ft_perror(const char *restrict parent, int errorcode,
	const char *restrict message)
{
	ft_message(ERROR_TOKEN, parent, errorcode, message);
}

inline void	ft_warning(const char *restrict parent, int errorcode,
	const char *restrict message)
{
	ft_message(WARNING_TOKEN, parent, errorcode, message);
}

inline void	ft_info(const char *restrict parent, int errorcode,
	const char *restrict message)
{
	ft_message(INFO_TOKEN, parent, errorcode, message);
}

inline void	ft_ok(const char *restrict parent, int errorcode,
	const char *restrict message)
{
	ft_message(OK_TOKEN, parent, errorcode, message);
}

void	ft_exit(int status)
{
	draw_image(1);
	free(get_data());
	gui_finalize();
	exit(status);
}
