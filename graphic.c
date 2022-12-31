/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:06:05 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/31 21:05:06 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lib.h"
 static int getColorX(int itr)
{
	int r;
	int g;
	int b;
	double D;
	if (itr < 2)
	return 0x000000;
	if (itr > MAX_ITRA - 5)
	return 0x0000ff;
	if (itr <= (MAX_ITRA / 2))
	{
		D = (double)itr / (double)MAX_ITRA;
		r = 0 * (1 - D) + D * 255;
		g = 0 * (1 - D) + D * 255;
		b = 255 * (1 - D) + D * 0;
}
else
{
	itr = itr - (MAX_ITRA / 2);
	D = (double)itr / (double) MAX_ITRA;
	r = 255 * (1 - D) + D * 8 ;
	g = 255 * (1 - D) + D *23;
	b = 0 * (1 - D) + D *120;
}


	return (0 << 24 | r << 16 | g << 8 | b);
}
/*
static  int getColor(int itr, int r, int g, int b)
{
	float ratio;
	if(itr < 3)
		return (0x000000);
	if (itr > 76)
		return (0xffffff);
	ratio = (float)itr / (float)MAX_ITRA;
	r = (int )(r * ratio);
	return (0 << 24 | r << 16 | g << 8 | b);
 }
 */

static void pixel_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
 }
double map(int pos, int len, double min , double max)
{

	double dis = fabs(max - min);
	double p = (double)pos /(double)len;
	double res = min + (p  * dis);
	return res;
}


void render(t_data *data)
{
	int	x;
	int	y;
	int itra;
	t_img img;

	x = 0;
	img.img = data->img;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			data->z.x = map(x, WIN_W, data->startx, data->endx);
			data->z.y = map(y, WIN_H, data->starty, data->endy);
			if(data->type == 1)
				itra = getiteration(newcomplex(0,0), data->z, 0);
			else if (data->type == 2)
				itra = getiteration(data->z, data->c,0);
			else
				itra = getiteration(newcomplex(0, 0), data->z, 1);
			// pixel_put(&img, x ,y, getColor(itra, 255, 58, 90));
			 pixel_put(&img, x ,y, getColorX(itra));
			y++;
		}
		x++;
	}
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img,0,0);
}

