/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:06:05 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/01 21:14:53 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	getcolor(int itr)
{
	if (itr < 10)
		return ((int)(255 - (2.55 * itr)));
	if (itr > 70)
		return ((int)((2.55 * (70 - itr))));
	return ((int)(0xffffff * fabs(cos(itr))));
}

static void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	map(int pos, int len, double min, double max)
{
	double	dis;
	double	res;
	double	p;

	dis = fabs(max - min);
	p = (double)pos / (double)len;
	res = min + (p * dis);
	return (res);
}

static void	fill_image(t_data *data, t_img *img)
{
	int	x;
	int	y;
	int	itra;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			data->z.x = map(x, WIN_W, data->startx, data->endx);
			data->z.y = -map(y, WIN_H, data->starty, data->endy);
			if (data->type == 1)
				itra = getiteration(newcomplex(0, 0), data->z, 0);
			else if (data->type == 2)
				itra = getiteration(data->z, data->c, 0);
			else
				itra = getiteration(newcomplex(0, 0), data->z, 1);
			pixel_put(img, x, y, getcolor(itra));
			y++;
		}
	x++;
	}
}

void	render(t_data *data)
{
	t_img	img;

	img.img = data->img;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	fill_image(data, &img);
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
