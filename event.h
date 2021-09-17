/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:24:11 by kostya            #+#    #+#             */
/*   Updated: 2021/09/17 22:55:11 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

int		ft_close_window(int __s, void *__d) __attribute__((noreturn));
int	ft_mouse_press(int key_code, int mouse_x, int mouse_y);
int		ft_button_press(int key_code, void *__d);
void	draw_image();

# define KEY_ESC	65307
# define NUM_UP		65431
# define NUM_DOWN	65433
# define NUM_LEFT	65430
# define NUM_RIGHT	65432

# define KEY_UP		65362
# define KEY_DOWN	65364

# define KEY_SPEED	0.05

#endif
