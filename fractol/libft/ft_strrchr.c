/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:15:26 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/09/29 18:51:50 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	char	*k;

	str = (char *)s;
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			k = &str[i];
		}
		i++;
	}
	if (str[i] == (char)c)
		k = &str[i];
	return (k);
}
