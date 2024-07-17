/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 05:47:27 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/05/30 04:33:50 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ship(t_data *img, int x, int y)
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
		img->a_y = fabs(2.0 * img->a_x * img->a_y) + img->caluc_y;
		img->a_x = fabs(temp_x);
		if (img->a_x * img->a_x + img->a_y * img->a_y >= __DBL_MAX__)
			break ;
		i++;
	}
	if (i == img->num_exe)
		my_mlx_pixel_put(img, x, y, 0x00000000);
	else
		my_mlx_pixel_put(img, x, y, img->fr_color * (i % 200));
}

void	fc_ship(t_data *img)
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
			ship(img, x, y);
			y++;
		}
		x++;
	}
}
