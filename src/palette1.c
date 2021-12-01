/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:09:03 by kostya            #+#    #+#             */
/*   Updated: 2021/10/02 19:12:41 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

int	__palette4_extension(FLOAT i);
int	__palette5_extension(FLOAT i);

int	palette4(FLOAT i)
/*
** MatPlotLib inferno palette
*/
{
	i = i * (i > 0);
	if (i < ONE_NINETH)
		return ((int)(198 * i + 0) << 16 | (int)(99 * i + 0) << 8 | (int)(477
			* i + 4));
	else if (i < 2 * ONE_NINETH)
		return ((int)(396 * i - 22) << 16 | (int)(-9 * i + 12) << 8 | (int)(423
			* i + 10));
	else if (i < 3 * ONE_NINETH)
		return ((int)(360 * i - 14) << 16 | (int)(117 * i - 16) << 8 | (int)(54
			* i + 92));
	else if (i < 4 * ONE_NINETH)
		return ((int)(369 * i - 17) << 16 | (int)(135 * i - 22) << 8 | (int)(-63
			* i + 131));
	else if (i < 5 * ONE_NINETH)
		return ((int)(350 * i - 8) << 16 | (int)(143 * i - 25) << 8 | (int)(-161
			* i + 174));
	else if (i < 6 * ONE_NINETH)
		return ((int)(315 * i + 10) << 16 | (int)(243 * i - 81) << 8 | (int)
			(-243 * i + 220));
	else if (i < 7 * ONE_NINETH)
		return ((int)(198 * i + 88) << 16 | (int)(333 * i - 141) << 8 | (int)
			(-279 * i + 244));
	else
		return (__palette4_extension(i));
}

inline int	__palette4_extension(FLOAT i)
{
	if (i < 8 * ONE_NINETH)
		return ((int)(80 * i + 180) << 16 | (int)(422 * i - 210) << 8 | (int)
			(-152 * i + 145));
	else
		return ((int)(-53 * i + 300) << 16 | (int)(449 * i - 234) << 8 | (int)
			(539 * i - 469));
}

int	palette5(FLOAT i)
/*
** Rainbow palette
*/
{
	if (i < ONE_NINETH)
		return ((int)(720 * i + 110) << 16 | (int)(-36 * i + 64) << 8 | (int)
			(45 * i + 170));
	else if (i < 2 * ONE_NINETH)
		return ((int)(576 * i + 126) << 16 | (int)(135 * i + 45) << 8 | (int)
			(-396 * i + 219));
	else if (i < 3 * ONE_NINETH)
		return ((int)(9 * i + 252) << 16 | (int)(396 * i - 13) << 8 | (int)
			(-540 * i + 251));
	else if (i < 4 * ONE_NINETH)
		return ((int)(-252 * i + 339) << 16 | (int)(567 * i - 70) << 8 | (int)
			(-216 * i + 143));
	else if (i < 5 * ONE_NINETH)
		return ((int)(-458 * i + 430) << 16 | (int)(512 * i - 45) << 8 | (int)
			(386 * i - 124));
	else if (i < 6 * ONE_NINETH)
		return ((int)(-837 * i + 641) << 16 | (int)(63 * i + 203) << 8 | (int)
			(108 * i + 29));
	else if (i < 7 * ONE_NINETH)
		return ((int)(-477 * i + 401) << 16 | (int)(-207 * i + 384) << 8 | (int)
			(540 * i - 258));
	else
		return (__palette5_extension(i));
}

inline int	__palette5_extension(FLOAT i)
{
	if (i < 8 * ONE_NINETH)
		return ((int)(44 * i - 4) << 16 | (int)(-458 * i + 579) << 8 | (int)
			(485 * i - 215));
	else
		return ((int)(368 * i - 292) << 16 | (int)(-548 * i + 659) << 8 | (int)
			(35 * i + 184));
}
