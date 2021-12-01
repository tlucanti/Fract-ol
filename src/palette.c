/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:06:20 by kostya            #+#    #+#             */
/*   Updated: 2021/10/02 19:09:43 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

int	__palette3_extension(FLOAT i);

int	palette1(FLOAT i)
/*
** Default Ultra Fractal (or Wikipedia) color palette
*/
{
	i = i * (i > 0);
	if (i < 0.2)
		return (((int)(i * (32 / 0.2)) << 16) | ((int)(i * (107 - 7) / 0.2 + 7)
				<< 8) | (int)(i * (203 - 100) / 0.2 + 100));
	else if (i < 0.4)
		return (((int)((i - 0.2) * (237 - 32) / 0.2 + 32) << 16) | ((int)((i
			- 0.2) * (255 - 107) / 0.2 + 107) << 8) | (int)((i - 0.2) * (255
			- 203) / 0.2 + 203));
	else if (i < 0.6)
		return (((int)((i - 0.4) * (255 - 237) / 0.2 + 237) << 16) | ((int)((i
			- 0.4) * (170 - 255) / 0.2 + 255) << 8) | (int)((i - 0.4) * (-255)
			/ 0.2 + 255));
	else if (i < 0.8)
		return (((int)((i - 0.6) * (-255) / 0.2 + 255) << 16) | ((int)((i - 0.6)
			* (2 - 170) / 0.2 + 170) << 8));
	else
		return (((int)((i - 0.8) * (7 - 2) / 0.2 + 2) << 8) | (int)((i - 0.8)
			* (100) / 0.2));
}

int	palette2(FLOAT i)
/*
** RGB spectrum palette
*/
{
	i = i * (i > 0);
	if (i < ONE_SIXTH)
		return (0xff0000 | (int)(255 * 6 * i) << 8);
	else if (i < 2 * ONE_SIXTH)
		return ((int)(255 * (1 - 6 * (i - ONE_SIXTH))) << 16 | 0xff00);
	else if (i < 3 * ONE_SIXTH)
		return (0xff00 | (int)(255 * 6 * (i - 2 * ONE_SIXTH)));
	else if (i < 4 * ONE_SIXTH)
		return ((int)(255 - 255 * 6 * (i - 3 * ONE_SIXTH)) << 8 | 0xff);
	else if (i < 5 * ONE_SIXTH)
		return ((int)(255 * 6 * (i - 4 * ONE_SIXTH)) << 16 | 0xff);
	else
		return (0xff0000 | (int)(255 * (1 - 6 * (i - 5 * ONE_SIXTH))));
}

int	palette3(FLOAT i)
/*
** MatPotLib Viridis palette
*/
{
	i = i * (i > 0);
	if (i < ONE_NINETH)
		return ((int)(36 * i + 68) << 16 | (int)(315 * i + 1) << 8 | (int)(297
			* i + 84));
	else if (i < 2 * ONE_NINETH)
		return ((int)(-63 * i + 79) << 16 | (int)(288 * i + 4) << 8 | (int)(162
			* i + 99));
	else if (i < 3 * ONE_NINETH)
		return ((int)(-108 * i + 89) << 16 | (int)(243 * i + 14) << 8 | (int)(54
			* i + 123));
	else if (i < 4 * ONE_NINETH)
		return ((int)(-99 * i + 86) << 16 | (int)(225 * i + 20) << 8 | (int)(9
			* i + 138));
	else if (i < 5 * ONE_NINETH)
		return ((int)(-80 * i + 77) << 16 | (int)(215 * i + 24) << 8 | (int)(-8
			* i + 146));
	else if (i < 6 * ONE_NINETH)
		return ((int)(9 * i + 27) << 16 | (int)(216 * i + 23) << 8 | (int)(-81
			* i + 186));
	else if (i < 7 * ONE_NINETH)
		return ((int)(288 * i - 158) << 16 | (int)(198 * i + 35) << 8 | (int)
			(-171 * i + 246));
	else
		return (__palette3_extension(i));
}

inline int	__palette3_extension(FLOAT i)
{
	if (i < 8 * ONE_NINETH)
		return ((int)(503 * i - 325) << 16 | (int)(170 * i + 57) << 8 | (int)
			(-287 * i + 336));
	else
		return ((int)(602 * i - 413) << 16 | (int)(125 * i + 97) << 8 | (int)
			(-386 * i + 424));
}
