/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:01:01 by kostya            #+#    #+#             */
/*   Updated: 2021/09/09 21:01:45 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

#include <malloc.h>

void	*xmalloc(size_t size) __attribute__((malloc)) __attribute__((warn_unused_result));

#endif
