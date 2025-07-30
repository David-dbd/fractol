/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:13:20 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/01/27 19:41:42 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		(sub_str = (char *)malloc(1 * sizeof(char)));
		if (sub_str == NULL)
		{
			return (NULL);
		}
		sub_str[0] = '\0';
		return (sub_str);
	}
	if (len >= s_len - start)
		len = s_len - start;
	sub_str = (char *)malloc((len + 1) * sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Casos de prueba
    const char *str1 = "Hello, world!";
    const char *str2 = "Substring test";
    const char *str3 = "Another test string";

    // Prueba con una subcadena válida
    char *sub1 = ft_substr(str1, 7, 5);
    if (sub1 != NULL)
    {
        printf("Sub1: %s\n", sub1); // Esperado: "world"
        free(sub1);
    }

    // Prueba con longitud mayor al tamaño de la cadena restante
    char *sub2 = ft_substr(str2, 5, 20);
    if (sub2 != NULL)
    {
        printf("Sub2: %s\n", sub2); // Esperado: "ing test"
        free(sub2);
    }

    // Prueba con posición de inicio fuera del tamaño de la cadena
    char *sub3 = ft_substr(str3, 50, 5);
    if (sub3 != NULL)
    {
        printf("Sub3: %s\n", sub3); // Esperado: ""
        free(sub3);
    }

    return 0;
}
*/
