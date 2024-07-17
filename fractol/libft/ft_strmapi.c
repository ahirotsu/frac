/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:20:55 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/09/29 18:12:11 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		k;
	char	*a;

	i = 0;
	if (s == NULL)
		return (NULL);
	k = (unsigned int)ft_strlen(s);
	a = (char *)malloc(sizeof(char) * (k + 1));
	if (a == NULL)
		return (NULL);
	while (i < k)
	{
		a[i] = f(i, s[i]);
		i++;
	}
	a[i] = '\0';
	return (a);
}
