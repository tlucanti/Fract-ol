/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:24:11 by kostya            #+#    #+#             */
/*   Updated: 2021/10/02 19:13:05 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

int		ft_close_window(void) __attribute__((noreturn));
int		ft_mouse_press(int key_code, int mouse_x, int mouse_y);
int		ft_button_press(int key_code, __attribute__((unused)) void *__d);
void	draw_image(int do_free);

# define KEY_SPEED		0.05
# define SCALE			1.2

#endif
