/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:48:59 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/01/28 16:40:15 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *ptr, int c)
{
	int	i;

	i = 0;
	while (ptr[i] != '\0')
		i++;
	if (c == '\0')
		return ((char *)&ptr[i]);
	while (i >= 0)
	{
		if (ptr[i] == c)
		{
			return ((char *)&ptr[i]);
		}
		i--;
	}
	return (NULL);
}
