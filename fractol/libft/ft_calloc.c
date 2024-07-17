/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:21:40 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/09/29 18:32:44 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;
	size_t	k;

	if (size == 0 || count == 0)
	{
		size = 1;
		count = 1;
	}
	if (size > SIZE_MAX / count)
		return (NULL);
	k = count * size;
	a = malloc(k);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, k);
	return (a);
}
