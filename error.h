/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:40:07 by kostya            #+#    #+#             */
/*   Updated: 2021/09/09 21:34:29 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_message(const char *type, const char *parent, int errorcode, char *message);
void	ft_perror(const char *parent, int errorcode, char *message);
void	ft_warning(const char *parent, int errorcode, char *message);
void	ft_ok(const char *parent, int errorcode, char *message);
void	ft_exit(int status) __attribute__((noreturn));
void	ft_perror_exit(const char *parent, int errorcode, char *message, int status) __attribute__((noreturn));

#define E_MLX_INIT	-2		// MLX ERROR
#define E_MALLOC	-3		// MALLOC_ERROR

#define K_CLOSED	-4		// MLX WINDOW CLOSED

#endif
