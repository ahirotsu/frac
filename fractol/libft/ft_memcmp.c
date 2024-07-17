/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:46:55 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/09/29 18:41:13 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*k;
	unsigned char	*p;
	size_t			i;

	k = (unsigned char *)s1;
	p = (unsigned char *)s2;
	i = 0;
	while (n > i)
	{
		if (k[i] != p[i])
		{
			return (k[i] - p[i]);
		}
		i++;
	}
	return (0);
}
