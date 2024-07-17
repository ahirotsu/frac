/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:23:08 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/09/29 18:51:54 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	mach_ch(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	check_bigin(char *s1, char const *set, size_t *len)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (mach_ch(s1[i], set) == 0)
			return (1);
		i++ ;
		(*len)--;
	}
	return (0);
}

static size_t	check_end(char *s1, char const *set, size_t len)
{
	while (1)
	{
		if (mach_ch(s1[len - 1], set) == 0)
			break ;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*a;
	size_t	len;
	size_t	k;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen((char *)s1);
	k = len;
	if (!check_bigin((char *)s1, set, &len))
		return (ft_strdup(""));
	k = k - len;
	len = check_end((char *)&s1[k], set, len);
	a = (char *)malloc(sizeof(char) * len + 1);
	if (a == NULL)
		return (NULL);
	ft_memcpy(a, &s1[k], len);
	a[len] = '\0';
	return (a);
}
