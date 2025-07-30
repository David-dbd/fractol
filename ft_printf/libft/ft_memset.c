/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:58:18 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/01/23 18:17:46 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t size)
{
	unsigned char	*d;
	size_t			i;

	d = (unsigned char *)ptr;
	i = 0;
	if ((value >= 0) && (value <= 255))
	{
		while (i < size)
		{
			d[i] = value;
			i++;
		}
	}
	else
	{
		value = value % 256;
		while (i < size)
		{
			d[i] = value;
			i++;
		}
	}
	return (ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>

char *ft_memset(char *ptr, int value, size_t size);

int main(void)
{
    size_t size = 10;
    char *block = (char *)malloc(size * sizeof(char));

    ft_memset(block, 'A', size);
    printf("Block (filled with 'A'): %s\n", block);

    ft_memset(block, 300, size);
    printf("Block (filled with 300 mod 256): %s\n", block);

    free(block);
    return 0;
}
*/
