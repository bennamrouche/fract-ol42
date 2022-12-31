/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:02:57 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/31 20:32:12 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"


int destory(void *ptr)
{
	t_data *data;

	data = (t_data *)ptr;

	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	exit(0);
	return (0);
}
static void	movex(t_data *data, int key)
{
	double dx;

	dx = fabs(data->startx - data->endx);
	if(key == KEY_LEFT)
	{
		data->startx += dx * 0.2;
		data->endx += dx * 0.2;
	}
	else
	{
		data->startx -= dx * 0.2;
		data->endx -= dx * 0.2;
	}
	render(data);

}

static void movey(t_data *data, int key)
{
	double dy;

	dy = fabs(data->starty - data->endy);
	if (key == KEY_DOWN)
	{
		data->starty -= dy * 0.2;
		data->endy -= dy * 0.2;
	}
	else
	{
		data->starty += dy * 0.2;
		data->endy += dy * 0.2;
	}
	render(data);
}

int keyclick(int key, void *ptr)
{
	t_data *data;

	data = (t_data *)ptr;

	if (key == KEY_ESC)
		destory(data);
	else if(key == KEY_SPACE)
	data->ismouse_enbale = !data->ismouse_enbale;
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		movex(data, key);
	else if (key == KEY_UP|| key == KEY_DOWN)
		movey(data, key);
	printf("click %d", key);
	return(0);
}


