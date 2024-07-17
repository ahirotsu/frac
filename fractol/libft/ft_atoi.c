/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:47:40 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/09/29 18:33:14 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	checklong(long n, int c, char *k)
{
	if (c == 1 && ((LONG_MAX / 10 < n)
			|| (LONG_MAX - n * 10 - (*k - '0') <= 0)))
		return (1);
	if (c == -1 && (((LONG_MIN / 10) > n)
			|| (LONG_MIN + n * 10 + (*k - '0') >= 0)))
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	char	*k;
	int		c;
	long	n;

	k = (char *)str;
	c = 1;
	n = 0;
	while (('\t' <= *k && *k <= '\r') || *k == ' ')
		k++;
	if (*k == '+' || *k == '-')
	{
		if (*k == '-')
			c = -1;
		k++;
	}
	while (ft_isdigit(*k) == 1)
	{
		if (c == 1 && (checklong(n, c, k) == 1))
			return (-1);
		if (c == -1 && (checklong(n, c, k) == -1))
			return (0);
		n = n * 10 + (*k - '0');
		k++;
	}
	return ((int)n * c);
}

// #include<stdio.h>

// int	main(void)
// {
// 	printf("%d\n", atoi("4294967297"));
// 	printf("%d\n", ft_atoi("4294967297"));
// 	return (0);
// }

// LONG_MAX + 1 (atoi("9223372036854775808"), ft_atoi("9223372036854775808"));
// LONG_MIN - 1 (atoi("-9223372036854775809"), ft_atoi("-9223372036854775809"));
// ULONG_MAX + 1(atoi("18446744073709551616"), ft_atoi("18446744073709551616"));
// SIZE_MAX + 1 (atoi("18446744073709551616"), ft_atoi("18446744073709551616"));
// ULONG_MAX - 1(atoi("18446744073709551614"), ft_atoi("18446744073709551614"));
// SIZE_MAX - 1 (atoi("18446744073709551614"), ft_atoi("18446744073709551614"));

// if (c == 1 && (unsigned int)n * 10 + (*k - '0') > 2147483647)
// 	return (-1);
// if (c == -1 && (unsigned int)n * 10 + (*k - '0') > 2147483648)
// 	return (0);