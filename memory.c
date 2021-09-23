/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:48:01 by kostya            #+#    #+#             */
/*   Updated: 2021/09/22 20:42:33 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "error.h"

void	*xmalloc(size_t size)
{
	register void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_perror("malloc", E_MALLOC, NULL);
		ft_exit(EXIT_FAILURE);
	}
	return (ptr);
}
