/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:36:02 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/06/07 20:51:03 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_putmg(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit (1);
	return (1);
}

int	ft_argvch(t_data *img, char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (i == 6)
	{
		if (ft_strncmp(argv, "mandel", 7))
			return (0);
		img->fr_nm = 0;
	}
	else if (i == 5)
	{
		if (ft_strncmp(argv, "julia", 6))
			return (0);
		img->fr_nm = 1;
	}
	else if (i == 4)
	{
		if (ft_strncmp(argv, "ship", 5))
			return (0);
		img->fr_nm = 2;
	}
	else
		return (0);
	return (1);
}

void	init_img(t_data *img, char *argv)
{
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, SIZE, SIZE, argv);
	img->img = mlx_new_image(img->mlx, SIZE, SIZE);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->x_f = -1.70;
	img->y_f = -1.50;
	img->zoom_lv = 300;
	img->mouse_x = 0;
	img->mouse_y = 0;
	img->fr_color = 0x00052410;
	if (NUM_CAL > INT_MAX || NUM_CAL < 0)
	{
		ft_putmg("please correct number of calculations ");
		exit(1);
	}
	img->num_exe = NUM_CAL;
	img->total_key = 0;
}

int	main(int argc, char **argv)
{
	t_data	*img;

	if (argc != 2 && argc != 4)
		return (ft_putmg("please mandel or julia, ship"));
	img = malloc(sizeof(t_data));
	if (!img)
		return (ft_putmg("malloc error"));
	if (!ft_argvch(img, argv[1]))
		return (ft_putmg("please mandel or julia, ship"));
	if (argc == 4)
		ch_julia(img, argv);
	init_img(img, argv[1]);
	if (argc == 2)
		img->rand_frag = 0;
	mlx_mouse_hook(img->mlx_win, mouse_accept, img);
	mlx_key_hook(img->mlx_win, key_accept, img);
	mlx_hook(img->mlx_win, 17, 0, exit_fr, img);
	fr_class(img);
	mlx_loop(img->mlx);
	return (0);
}
