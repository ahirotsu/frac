/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:00:23 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/06/07 21:01:51 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	exit_fr(t_data *img)
{
	if (!img)
		exit(0);
	if (img->img)
		mlx_destroy_image(img->mlx, img->img);
	if (img->mlx_win && img->mlx)
		mlx_destroy_window(img->mlx, img->mlx_win);
	if (img->mlx)
	{
		mlx_loop_end(img->mlx);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
	}
	if (img)
		free(img);
	exit(0);
	return (0);
}

static void	zoom_func(t_data *img, int x, int y, char a)
{
	double	zoom_mang;

	zoom_mang = 1.35;
	if (a == '+')
	{
		img->x_f = (x / img->zoom_lv + img->x_f) - (x
				/ (img->zoom_lv * zoom_mang));
		img->y_f = (y / img->zoom_lv + img->y_f) - (y
				/ (img->zoom_lv * zoom_mang));
		img->zoom_lv *= zoom_mang;
	}
	else if (a == '-')
	{
		img->x_f = (x / img->zoom_lv + img->x_f) - (x
				/ (img->zoom_lv / zoom_mang));
		img->y_f = (y / img->zoom_lv + img->y_f) - (y
				/ (img->zoom_lv / zoom_mang));
		img->zoom_lv /= zoom_mang;
	}
	else
		return ;
}

static void	big_move(int key, t_data *img)
{
	if (key == A)
		img->x_f = img->x_f - 100 / img->zoom_lv;
	else if (key == D)
		img->x_f = img->x_f + 100 / img->zoom_lv;
	else if (key == W)
		img->y_f = img->y_f - 100 / img->zoom_lv;
	else if (key == S)
		img->y_f = img->y_f + 100 / img->zoom_lv;
}

int	key_accept(int key, t_data *img)
{
	sum_keymouse(img, key);
	if (key == ESC)
		exit(0);
	else if (key == LEFT)
		img->x_f = img->x_f - 25 / img->zoom_lv;
	else if (key == RIGHT)
		img->x_f = img->x_f + 25 / img->zoom_lv;
	else if (key == UP)
		img->y_f = img->y_f - 25 / img->zoom_lv;
	else if (key == DOWN)
		img->y_f = img->y_f + 25 / img->zoom_lv;
	else if (key == W || key == A || key == S || key == D)
		big_move(key, img);
	else if (key == I || key == R)
		number_exe(img, key);
	else if (key == J)
		set_julia(img);
	else if (key == M)
		move_julia(img);
	color_decide(img, key);
	fr_class(img);
	return (0);
}

int	mouse_accept(int mouse, int x, int y, t_data *img)
{
	sum_keymouse(img, mouse);
	img->mouse_x = x;
	img->mouse_y = y;
	if (mouse == S_UP)
	{
		zoom_func(img, x, y, '+');
	}
	else if (mouse == S_DOWN)
	{
		zoom_func(img, x, y, '-');
	}
	color_decide(img, mouse);
	fr_class(img);
	return (0);
}
