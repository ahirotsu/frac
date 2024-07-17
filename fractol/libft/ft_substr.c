/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:09:52 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/09/29 18:51:59 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*a;
	char				*k;
	unsigned int		s_len;
	unsigned int		a_len;

	if (s == NULL)
		return (NULL);
	s_len = (unsigned int)ft_strlen((char *)s);
	if (s_len > (unsigned int)len)
		a_len = (unsigned int)len;
	else
		a_len = s_len;
	if (s_len < start)
		return (ft_strdup(""));
	a = (char *)malloc(sizeof(char) * a_len + 1);
	if (a == NULL)
		return (NULL);
	k = a;
	s += start;
	while (a_len--)
		*a++ = *s++;
	*a = '\0';
	return (k);
}
