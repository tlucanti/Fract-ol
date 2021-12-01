/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:01:01 by kostya            #+#    #+#             */
/*   Updated: 2021/12/01 13:07:11 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H
# ifdef __linux__
#  include <malloc.h>
# endif
# ifdef __APPLE__
#  include <stdlib.h>
# endif

void	*xmalloc(size_t size) __attribute__((malloc, warn_unused_result));

#endif
