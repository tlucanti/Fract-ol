/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:24:11 by kostya            #+#    #+#             */
/*   Updated: 2021/09/23 19:52:55 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

int		ft_close_window(void) __attribute__((noreturn));
int		ft_mouse_press(int key_code, int mouse_x, int mouse_y);
int		ft_button_press(int key_code, __attribute__((unused)) void *__d);
void	draw_image(int do_free);

# define KEY_ESC	65307
# define NUM_UP		65431
# define NUM_DOWN	65433
# define NUM_LEFT	65430
# define NUM_RIGHT	65432

# define KEY_SPEED	0.05
# define KEY_UP		65362
# define KEY_DOWN	65364

# define SCALE		1.2

#endif
