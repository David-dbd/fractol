/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:54:31 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/01/28 15:14:55 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *source, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (ft_strlen(source));
	while (source[i] != '\0' && i < len - 1)
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	while (source[i] != '\0')
		i++;
	return (i);
}
