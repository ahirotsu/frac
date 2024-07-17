/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:55:26 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/06/07 21:04:13 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define JULIA_A -0.745429
# define JULIA_B 0.05
# define SIZE 1024
# define NUM_CAL 50
# define S_UP 4
# define S_DOWN 5
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define I 105
# define R 114
# define J 106
# define M 109
# define W 119
# define A 97
# define S 115
# define D 100

# include <limits.h>
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	int		fr_color;
	int		fr_nm;
	double	zoom_lv;
	double	x_f;
	double	y_f;
	double	a_x;
	double	a_y;
	double	caluc_x;
	double	caluc_y;
	int		mouse_x;
	int		mouse_y;
	int		num_exe;
	int		rand_frag;
	int		total_key;
}			t_data;

void	fr_class(t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		mouse_accept(int mouse, int x, int y, t_data *img);
int		key_accept(int key, t_data *img);
int		exit_fr(t_data *img);
void	color_decide(t_data *img, int ex);
int		ft_putmg(char *str);
void	number_exe(t_data *img, int key);
void	set_julia(t_data *img);
void	sum_keymouse(t_data *img, int ex);
void	move_julia(t_data *img);
void	fc_ship(t_data *img);
void	ch_julia(t_data *img, char **argv);

#endif