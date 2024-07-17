/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:22:25 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/09/29 18:42:58 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*l;
	char	*k;

	if (dst == NULL && src == NULL)
		return (dst);
	l = (char *)dst;
	k = (char *)src;
	if (l < k)
	{
		while (len--)
			*l++ = *k++;
	}
	else
	{
		l += len - 1;
		k += len - 1;
		while (len--)
		{
			*l-- = *k--;
		}
	}
	return (dst);
}
