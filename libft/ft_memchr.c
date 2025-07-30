/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:19:09 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/01/28 14:57:47 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	*d;
	unsigned char	c;
	size_t			i;

	d = (unsigned char *)ptr;
	c = (unsigned char)value;
	i = 0;
	while ((i < num))
	{
		if (d[i] == c)
		{
			return (d + i);
		}
		i++;
	}
	return (NULL);
}
