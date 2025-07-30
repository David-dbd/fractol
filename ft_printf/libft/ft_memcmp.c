/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:16:46 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/01/23 18:15:04 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*d;
	unsigned char	*c;
	size_t			i;

	i = 0;
	d = (unsigned char *)ptr1;
	c = (unsigned char *)ptr2;
	while (i < num)
	{
		if (d[i] != c[i])
		{
			return (d[i] - c[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int ft_memcmp(const void *ptr1, const void *ptr2, size_t num);

int main(void)
{
    // Ejemplo de datos
    char str1[] = "abcdef";
    char str2[] = "abcdez";
    char str3[] = "abcdef";
    char str4[] = "abcde";

    // Comparar las cadenas
    printf("Compar str1 and str2: %d\n", ft_memcmp(str1, str2, 6)); // Diferent
    printf("Compar str1 and str3: %d\n", ft_memcmp(str1, str3, 6)); // Igual
    printf("Compar str1 and str4: %d\n", ft_memcmp(str1, str4, 5));//Segúnlongi

    return 0;
}
*/
