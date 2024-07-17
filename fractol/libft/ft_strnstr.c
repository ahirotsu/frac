/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:59:31 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/09/29 18:51:43 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*s;
	size_t	n_len;
	size_t	i;

	i = 0;
	s = (char *)haystack;
	n_len = ft_strlen((char *)needle);
	if (n_len <= 0)
		return (s);
	if (len <= 0)
		return (NULL);
	while (len - n_len >= i)
	{
		if (s[i] == '\0' || i + n_len > len)
			return (NULL);
		if (ft_strncmp(&s[i], needle, n_len) == 0)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
