/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:57:35 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/09/29 18:51:14 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	k;

	srclen = ft_strlen((char *)src);
	if (dst == NULL && dstsize == 0)
		return (srclen);
	dstlen = ft_strlen(dst);
	k = dstlen + srclen;
	i = 0;
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	while (dstsize - dstlen - 1 > 0 && src[i] != '\0')
	{
		dst[dstlen + i] = src[i];
		dstsize--;
		i++;
	}
	dst[dstlen + i] = '\0';
	return (k);
}
