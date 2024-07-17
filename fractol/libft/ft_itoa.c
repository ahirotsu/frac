/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:33:13 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/09/27 14:28:20 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*ft_min(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 12);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, "-2147483648\0", 12);
	return (str);
}

static int	digift(int n)
{
	int	digi;

	digi = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		digi++;
	}
	return (digi);
}

static char	*mainitoa(char *ans, int flag, int k, int n)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		n = n * -1;
		ans[i] = '-';
	}
	ans[k + flag] = '\0';
	if (n == 0)
		ans[k + flag - i - 1] = '0';
	while (k + flag - i > 0 && n != 0)
	{
		ans[k + flag - i - 1] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	return (ans);
}

char	*ft_itoa(int n)
{
	int		flag;
	int		k;
	char	*ans;

	flag = 0;
	if (n == -2147483648)
		return (ft_min());
	if (n < 0)
		flag = 1;
	k = digift(n);
	ans = (char *)malloc(sizeof(char) * k + flag + 1);
	if (ans == NULL)
		return (NULL);
	return (mainitoa(ans, flag, k, n));
}

// #include<stdio.h>

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-345034560));
// 	return (0);
// }
