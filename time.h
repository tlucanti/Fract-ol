/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:47:51 by kostya            #+#    #+#             */
/*   Updated: 2021/09/13 20:28:06 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

struct timeval *get_time()
{
	static struct timeval	time;

	return (&time);
}

void	time_start(void)
{
	gettimeofday(get_time(), NULL);
}

double	time_stop(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return time.tv_sec - get_time()->tv_sec + (time.tv_usec - get_time()->tv_usec) * 1e-6;
}
