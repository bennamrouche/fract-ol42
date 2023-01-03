/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:29:00 by ebennamr          #+#    #+#             */
/*   Updated: 2023/01/01 20:11:20 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

// event definee
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17
// number
# define WIN_W 600
# define WIN_H 600
# define MAX_ITRA 80
// string
# define JULIA "Julia"
# define MANDELBORT "Mandelbrot"
# define BURNING "Burning"
//  error
# define ER_INV "invalid args :)"
# define ER_FRACT_NAME "fractal not exist  !!"
# define ER_JULIA_INV "julia: invalid args :) \
hint : Julia numbe1 €[0,600] number2€[0,600]"
// buttom
# define KEY_ESC  53
# define KEY_SPACE 49
# define KEY_UP  126
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_RIGHT 124
//mouse
# define MOUSE_SCROLL_UP 5
# define MOUSE_SCROLL_DOWN 4
#endif
