/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:34:48 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/09/29 18:41:37 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*l;
	unsigned char	*k;
	int				i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	l = (unsigned char *)dst;
	k = (unsigned char *)src;
	while (n)
	{
		l[i] = k[i];
		i++;
		n--;
	}
	return (dst);
}
