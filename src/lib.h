/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:30:50 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/01 21:18:44 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include "const.h"

typedef struct s_complex
{
	double	x;
	double	y;
}t_complex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	double		startx;
	double		endx;
	double		starty;
	double		endy;
	t_complex	z;
	t_complex	c;
	int			type;
	int			ismouse_enbale;
}t_data;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

//event function
int			mouse_move(int x, int y, t_data *data);
int			destory(void *ptr);
int			keyclick(int key, void *ptr);
int			mouse_scroll(int btn, int x, int y, void *ptr);
	// string function
void		ft_error(char *err);
size_t		ft_strlen( char *str);
int			ft_strncmp(char *s1, char *s2, size_t n);
int			is_digit(char *str);
int			ft_atoi(char *str);
	// complex fiunction
double		getmodduls(t_complex z);
t_complex	getpower2(t_complex z, int abs);
t_complex	getsum(t_complex z1, t_complex z2);
int			getiteration(t_complex zn, t_complex c, int abs);
t_complex	newcomplex(double x, double y);
//graphics
void		render(t_data *data);
double		map(int pos, int len, double min, double max);
#endif
