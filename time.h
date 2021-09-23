/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:47:51 by kostya            #+#    #+#             */
/*   Updated: 2021/09/22 20:42:27 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include <sys/time.h>

struct timeval	*get_time(void)
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
	return (time.tv_sec - get_time()->tv_sec
		+ (time.tv_usec - get_time()->tv_usec) * 1e-6);
}

#endif
