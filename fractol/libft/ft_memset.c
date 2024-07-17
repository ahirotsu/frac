/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:26:24 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/09/29 18:48:47 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	k;
	unsigned char	*l;

	k = (unsigned char)c;
	l = (unsigned char *)b;
	while (len > 0)
	{
		*l++ = k;
		len--;
	}
	return (b);
}
