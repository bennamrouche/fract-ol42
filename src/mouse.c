/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 21:34:27 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/01 20:20:21 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void	zoom_in(t_data *data, t_complex mouse_pos)
{
	data->startx += mouse_pos.x;
	data->endx += mouse_pos.x;
	data->starty += mouse_pos.y;
	data->endy += mouse_pos.y;
	data->startx = data->startx * 0.5;
	data->endx = data->endx * 0.5;
	data->starty = data->starty * 0.5;
	data->endy = data->endy * 0.5;
	render(data);
}

static void	zoom_out(t_data *data, t_complex mouse_pos)
{
	data->startx = data->startx / 0.5;
	data->endx = data->endx / 0.5;
	data->starty = data->starty / 0.5;
	data->endy = data->endy / 0.5;
	data->startx -= mouse_pos.x;
	data->endx -= mouse_pos.x;
	data->starty -= mouse_pos.y;
	data->endy -= mouse_pos.y;
	render(data);
}

int	mouse_move(int x, int y, struct s_data *data)
{
	if (data->type == 2 && data->ismouse_enbale == 1)
	{
		data->c.x = map(x, WIN_W, data->startx, data->endx);
		data->c.y = map(y, WIN_H, data->starty, data->endy);
		render(data);
	}
	return (0);
}

int	mouse_scroll(int btn, int x, int y, void *ptr)
{
	t_data		*data;
	t_complex	comp;

	data = (t_data *)(ptr);
	comp.x = map(x, WIN_W, data->startx, data->endx);
	comp.y = map(y, WIN_H, data->starty, data->endy);
	if (btn == MOUSE_SCROLL_UP)
		zoom_out(data, comp);
	else if (btn == MOUSE_SCROLL_DOWN)
		zoom_in(data, comp);
	return (0);
}
