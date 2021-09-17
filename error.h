/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:40:07 by kostya            #+#    #+#             */
/*   Updated: 2021/09/17 19:30:03 by kostya           ###   ########.fr       */
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
void	ft_info(const char *parent, int errorcode, char *message);
void	ft_exit(int status) __attribute__((noreturn));
void	ft_perror_exit(const char *parent, int errorcode, char *message, int status) __attribute__((noreturn));
void	ft_info_exit(const char *parent, int errorcode, char *message) __attribute__((noreturn));
void	print_help_message(void) __attribute__((noreturn));

#define E_MLX_INIT	-2		// MLX ERROR
#define E_MALLOC	-3		// MALLOC_ERROR
#define E_SET_TYPE	-4		// SET CHOOSING TYPE ERROR
#define E_RES_INP	-5		// RESOLUTION PARCE ERROR
#define E_RES_LIM	-6		// RESOLUTION LIMITS ERROR
#define E_CNT_INP	-7		// CENTER PARCE ERROR
#define E_UNREC_OPT	-8		// UNRECOGNIZED OPTION
#define E_REQ_LIM	-9		// RECURSION DEPTH LIMIT ERROR

#define K_CLOSED	-10		// MLX WINDOW CLOSED

#define PARAM_INFO	-11		// INFO ABOUT AVALIABLE PARAMS

#endif
