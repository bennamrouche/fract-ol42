/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:13:11 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/31 17:05:13 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
# include <stdio.h>
double	getmodduls(t_complex z)
{
	double	mod;

	mod = sqrt((z.x * z.x) + ((z.y * z.y)));
	return (mod);
}

t_complex	getpower2(t_complex z,int abs)
{
	t_complex z2;

	z2.x = (z.x * z.x) - (z.y * z.y);
	if (abs == 0)
		z2.y = 2 * z.x * z.y;
	else
		z2.y = 2 * fabs(z.x * z.y);
	return (z2);
}

t_complex	newcomplex(double x, double y)
{
	t_complex	com;
	com.x = x;
	com.y = y;
	return (com);
}

t_complex	getsum(t_complex z1, t_complex z2)
{
	return (newcomplex(z1.x + z2.x, z1.y + z2.y));
}

int getiteration(t_complex zn, t_complex c, int abs)
{
	t_complex	tmp;
	int			order;
	double		mod;
	tmp = getsum(zn,c);
	mod = getmodduls(tmp);
	order = 0;
	while (mod > 0 && mod <= 2 && order < MAX_ITRA)
	{
		tmp = getpower2(tmp, abs);
		tmp = getsum(tmp, c);
		mod = getmodduls(tmp);
		order++;
	}
	if (mod == 0)
		return (MAX_ITRA);
	return (order);
}
