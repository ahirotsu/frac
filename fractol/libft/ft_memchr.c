/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:35:59 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/09/29 18:40:37 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	p;

	i = 0;
	str = (unsigned char *)s;
	p = (unsigned char)c;
	while (n > i)
	{
		if (str[i] == p)
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
