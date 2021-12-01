/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_screen_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:18:32 by tlucanti          #+#    #+#             */
/*   Updated: 2021/10/14 17:18:44 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__

void	mlx_get_screen_size(__attribute__((unused))void *mlx, int *width,
	int *height)
{
	*width = 5120;
	*height = 2880;
}

#endif
