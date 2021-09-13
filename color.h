/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:23:37 by kostya            #+#    #+#             */
/*   Updated: 2021/09/13 23:00:02 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define TERM_BLACK		"\e[1;90m"
# define TERM_RED		"\e[1;91m"
# define TERM_GREEN		"\e[1;92m"
# define TERM_YELLOW	"\e[1;93m"
# define TERM_BLUE		"\e[1;94m"
# define TERM_PURPLE	"\e[1;95m"
# define TERM_CYAN		"\e[1;96m"
# define TERM_WHITE		"\e[1;97m"
# define TERM_RESET		"\e[0m"

# define OK				TERM_GREEN
# define WARNING		TERM_YELLOW
# define ERROR			TERM_RED
# define INFO			TERM_BLUE
# define RESET			TERM_RESET

#endif
