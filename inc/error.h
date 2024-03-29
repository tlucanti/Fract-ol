/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:40:07 by kostya            #+#    #+#             */
/*   Updated: 2021/09/23 23:07:24 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	ft_perror(const char *restrict parent, int errorcode,
			const char *restrict message);
void	ft_warning(const char *restrict parent, int errorcode,
			const char *restrict message);
void	ft_ok(const char *restrict parent, int errorcode,
			const char *restrict message);
void	ft_info(const char *restrict parent, int errorcode,
			const char *restrict message);
void	ft_exit(int status) __attribute__((noreturn));
void	ft_perror_exit(const char *restrict parent, int errorcode,
			const char *restrict message, int status) __attribute__((noreturn));
void	ft_info_exit(const char *restrict parent, int errorcode,
			const char *restrict message) __attribute__((noreturn));
void	print_help_message(void) __attribute__((noreturn));

# define E_MLX_INIT		(-2)
# define E_MALLOC		(-3)
# define E_SET_TYPE		(-4)
# define E_RES_INP		(-5)
# define E_RES_LIM		(-6)
# define E_CNT_INP		(-7)
# define E_UNREC_OPT		(-8)
# define E_REQ_LIM		(-9)
# define E_SCHEME_INP		(-10)
# define E_SCREENSHOT		(-11)

# define W_SHEME_M		(-12)
# define W_SHEME_J		(-13)
# define W_SHEME_N		(-14)

# define K_CLOSED		(-15)
# define K_SCREENSHOT		(-16)

# define I_PARAM		(-17)

#endif
