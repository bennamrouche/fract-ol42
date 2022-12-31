/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:09:41 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/31 20:03:28 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lib.h"

static void data_init(t_data *data, int type, char *tilte, t_complex newc)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, tilte);
	data->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->startx = -2;
	data->endx = 2;
	data->starty = -2;
	data->endy = 2;
	data->c = newcomplex(newc.x, newc.y);
	data->z = newcomplex(0, 0);
	data->type = type;
	data->ismouse_enbale = 1;

}
static void even_init(t_data *data)
{
	mlx_hook(data->win, ON_MOUSEMOVE, 0, &mouse_move, data);
	mlx_hook(data->win, ON_DESTROY, 0, &destory, data);
	mlx_hook(data->win, ON_KEYDOWN, 0, &keyclick, data);
	mlx_hook(data->win, ON_MOUSEDOWN,0, &mouse_scroll, data);
}
static int jluiacheck(int ac, char **av, t_data *data)
{
	int	x;
	int	y;
	printf("<< Julia <|>check >>");
	if (ac != 4)
		ft_error(ER_JULIA_INV);
	if (!(is_digit(av[2]) && is_digit(av[3])))
		ft_error(ER_JULIA_INV);
	x = ft_atoi(av[2]);
	y = ft_atoi(av[3]);
	data->c.x = map(x, WIN_W, -2, 2);
	data->c.y = map(y, WIN_H, -2, 2);
	return (1);
}
int	main(int ac, char **av)
{
	t_data	data;

	dup2(2,1);
	if(ac != 2 &&  ac != 4)
		ft_error(ER_INV);
	if (ft_strncmp(av[1], MANDELBORT, ft_strlen(MANDELBORT)) == 0)
		data_init(&data, 1, MANDELBORT, newcomplex(0, 0));
	else if (ft_strncmp(av[1], JULIA, ft_strlen(JULIA)) == 0 && jluiacheck(ac, av, &data))
		data_init(&data, 2, JULIA, newcomplex(data.c.x, data.c.y));
	else if (ft_strncmp(av[1], BURNING, ft_strlen(BURNING)) == 0)
		data_init(&data, 3, BURNING, newcomplex(0, 0));
	else
		ft_error(ER_FRACT_NAME);
	even_init(&data);
	render(&data);
	mlx_loop(data.mlx);

}
