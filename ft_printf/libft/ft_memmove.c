/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:49:01 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/01/21 15:28:04 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		while (n--)
		{
			*(d + n) = *(s + n);
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>

void *ft_memmove(void *dest, const void *src, size_t n);

int main(void)
{
    // Definir bloque de memoria
    size_t size = 15;
    char src[] = "Overlap Test";
    char *dest = (char *)malloc(size * sizeof(char));

    // Inicializar dest
    ft_memset(dest, 0, size);

    // Copiar con ft_memmove
    ft_memmove(dest, src, size - 1); // Copia src a dest

    // Mostrar resultados
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);

    // Caso de superposición
    char src2[] = "Hello World!";
    ft_memmove(src2 + 6, src2, 6); // M
*/
