/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:55:55 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/01/29 15:25:02 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	space_left;
	size_t	src_len;
	size_t	x;

	x = 0;
	i = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (len == 0)
	{
		return (src_len);
	}
	if (i >= len)
	{
		return (len + src_len);
	}
	space_left = len - i - 1;
	while ((src[x] != '\0') && (x < space_left))
	{
		dest[i + x] = src[x];
		x++;
	}
	dest[i + x] = '\0';
	return (i + src_len);
}
/*
int main(void)
{
    char name[10] = "David";
    char last[] = "Diaz";
    ft_strlcat(name, last, 10);
    printf("%s",name);
    return (0);
}*/
