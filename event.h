/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:24:11 by kostya            #+#    #+#             */
/*   Updated: 2021/09/13 22:28:14 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

int		ft_close_window(int __s, void *__d) __attribute__((noreturn));
int	ft_mouse_press(int key_code, int mouse_x, int mouse_y);
int		ft_button_press(int key_code, void *__d);
void	draw_image();

#endif
