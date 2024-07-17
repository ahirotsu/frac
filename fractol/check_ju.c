/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ju.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:24:30 by ahirotsu          #+#    #+#             */
/*   Updated: 2024/06/07 21:05:34 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (c);
	return (0);
}

static int	skip_space_sign(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

static double	ft_atof(char *argv)
{
	double	nb;
	double	div;
	int		i;
	int		is_neg;

	nb = 0;
	div = 0.1;
	is_neg = 1;
	i = skip_space_sign(argv, &is_neg);
	while (argv[i] && ft_isdigit(argv[i]) && argv[i] != '.')
	{
		nb = (nb * 10.0) + (argv[i] - '0');
		i++;
	}
	if (argv[i] == '.')
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
	{
		nb = nb + ((argv[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (argv[i] && !ft_isdigit(argv[i]))
		return (-42);
	return (nb * is_neg);
}

void	ch_julia(t_data *img, char **argv)
{
	if (img->fr_nm == 0 || img->fr_nm == 2)
		ft_putmg("mandel and ship must have 1 argument");
	img->caluc_x = ft_atof(argv[2]);
	img->caluc_y = ft_atof(argv[3]);
	if (img->caluc_x >= 2.0 || img->caluc_x <= -2.0
		|| img->caluc_y >= 2.0 || img->caluc_y <= -2.0)
		ft_putmg("Please enter numbers (2.0 > a > -2.0)");
	img->rand_frag = 1;
}
