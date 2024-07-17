/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:24:13 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/05/29 05:54:28 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	julia(t_data *img, int x, int y)
{
	double	temp_x;
	int		i;

	i = 0;
	img->a_x = (x / img->zoom_lv) + img->x_f;
	img->a_y = (y / img->zoom_lv) + img->y_f;
	while (i < img->num_exe)
	{
		temp_x = img->a_x * img->a_x - img->a_y * img->a_y + img->caluc_x;
		img->a_y = 2.0 * img->a_x * img->a_y + img->caluc_y;
		img->a_x = temp_x;
		if (img->a_x * img->a_x + img->a_y * img->a_y >= __DBL_MAX__)
			break ;
		i++;
	}
	if (i == img->num_exe)
		my_mlx_pixel_put(img, x, y, 0x00000000);
	else
		my_mlx_pixel_put(img, x, y, img->fr_color * (i % 200));
}

void	fc_julia(t_data *img)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < SIZE)
	{
		y = 0;
		while (y < SIZE)
		{
			julia(img, x, y);
			y++;
		}
		x++;
	}
}

void	mandel(t_data *img, int x, int y)
{
	double	temp_x;
	int		i;

	i = 0;
	img->a_x = 0.0;
	img->a_y = 0.0;
	img->caluc_x = (x / img->zoom_lv) + img->x_f;
	img->caluc_y = (y / img->zoom_lv) + img->y_f;
	while (i < img->num_exe)
	{
		temp_x = img->a_x * img->a_x - img->a_y * img->a_y + img->caluc_x;
		img->a_y = 2.0 * img->a_x * img->a_y + img->caluc_y;
		img->a_x = temp_x;
		if (img->a_x * img->a_x + img->a_y * img->a_y >= __DBL_MAX__)
			break ;
		i++;
	}
	if (i == img->num_exe)
		my_mlx_pixel_put(img, x, y, 0x00000000);
	else
		my_mlx_pixel_put(img, x, y, img->fr_color * (i % 200));
}

void	fc_mandel(t_data *img)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < SIZE)
	{
		y = 0;
		while (y < SIZE)
		{
			mandel(img, x, y);
			y++;
		}
		x++;
	}
}

void	fr_class(t_data *img)
{
	if (img->fr_nm == 0)
		fc_mandel(img);
	else if (img->fr_nm == 1)
	{
		if (img->rand_frag == 0)
		{
			img->caluc_x = JULIA_A;
			img->caluc_y = JULIA_B;
		}
		fc_julia(img);
	}
	else if (img->fr_nm == 2)
		fc_ship(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
