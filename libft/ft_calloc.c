/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:08:13 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/01/23 16:56:36 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*ptr;
	size_t			total_size;
	size_t			i;

	i = 0;
	if (num == 0 || size == 0)
	{
		return ((void *)malloc(0));
	}
	total_size = num * size;
	ptr = (unsigned char *)malloc(total_size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>

void *ft_calloc(size_t num, size_t size);

int main(void)
{
    // Número de elementos y tamaño de cada elemento
    size_t num_elements = 5;
    size_t element_size = sizeof(int);

    // Reservar memoria usando ft_calloc
    int *array = (int *)ft_calloc(num_elements, element_size);

    // Verificar si la memoria se reservó correctamente
    if (array == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Mostrar los valores iniciales del array
    for (size_t i = 0; i < num_elements; i++)
    {
        printf("array[%zu] = %d\n", i, array[i]);
    }

    // Liberar la memoria reservada
    free(array);

    return 0;
}
*/
