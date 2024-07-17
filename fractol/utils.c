/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:24:06 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/05/30 01:19:04 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	sum_keymouse(t_data *img, int ex)
{
	if (0 < img->total_key + ex)
		img->total_key = 0;
	else
		img->total_key += ex;
}

void	set_julia(t_data *img)
{
	double	a;
	double	b;

	a = cos(img->a_x + img->x_f + (double)img->fr_color
			+ img->caluc_x + (double)img->mouse_x);
	b = cos(img->a_y + img->y_f + (double)img->fr_color
			+ img->caluc_y + (double)img->mouse_y);
	if (img->total_key % 2)
		a *= -1;
	if (img->total_key % 3)
		b *= -1;
	img->caluc_x = a;
	img->caluc_y = b;
	img->rand_frag = 1;
}

void	move_julia(t_data *img)
{
	if (img->fr_nm == 1)
	{
		img->caluc_x += 0.01;
		img->caluc_y -= 0.01;
		img->rand_frag = 1;
	}
}

void	number_exe(t_data *img, int key)
{
	if (key == I)
	{
		if (0 < INT_MAX - img->num_exe - 50)
			img->num_exe = img->num_exe + 50;
	}
	else
	{
		if (img->num_exe > 50)
			img->num_exe = img->num_exe - 50;
	}
}

void	color_decide(t_data *img, int ex)
{
	if (0xFFFFFFFF
		< (0x00052410 + (img->mouse_x + img->mouse_y) % 255 + ex) * 200)
	{
		img->fr_color = 0x00052410;
		return ;
	}
	img->fr_color = img->fr_color + (img->mouse_x + img->mouse_y) % 255 + ex;
}
