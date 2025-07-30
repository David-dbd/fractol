/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:13:58 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/01/23 18:12:42 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Tamaño del bloque de memoria
    size_t size = 10;
    char src[] = "Hello";
    char *dest = (char *)malloc(size * sizeof(char));

    // Inicializar el destino
    ft_memset(dest, 0, size);

    // Copiar contenido de src a dest
    ft_memcpy(dest, src, size);

    // Mostrar resultados
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);

    free(dest);
    return 0;
}
*/
