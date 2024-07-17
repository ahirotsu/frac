/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:04:42 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/09/20 14:20:17 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isalpha(int c)
{
	if (('a' <= c && 'z' >= c) || ('A' <= c && 'Z' >= c))
	{
		return (1);
	}
	return (0);
}

// #include<stdio.h>
// #include<ctype.h>

// int	main(void)
// {
// 	printf("%d\n", ft_isalpha('S'));
// 	printf("%d\n", ft_isalpha(120));
// 	printf("%d\n", ft_isalpha(10));
// 	printf("%d\n", isalpha('S'));
// 	printf("%d\n", isalpha(120));
// 	printf("%d\n", isalpha(10));
// }
