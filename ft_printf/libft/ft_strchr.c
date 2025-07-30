/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:54:03 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/01/29 18:48:05 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	d;
	int				i;

	i = 0;
	d = (unsigned char)c;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == d)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (d == '\0')
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *str = "Hello, world!";
    char *result;

    // Prueba con un carácter que existe en la cadena
    result = ft_strchr(str, 'w');
    if (result)
    {
        printf("Character 'w' found: %s\n", result);
    }
    else
    {
        printf("Character 'w' not found.\n");
    }

    // Prueba con un carácter que no existe en la cadena
    result = ft_strchr(str, 'z');
    if (result)
    {
        printf("Character 'z' found: %s\n", result);
    }
    else
    {
        printf("Character 'z' not found.\n");
    }

    // Prueba con el carácter nulo
    result = ft_strchr(str, '\0');
    if (result)
    {
        printf("Char '\\0' fond: %s\n",(result ? "end of string" : "NULL"));
    }
    else
    {
        printf("Character '\\0' not found.\n");
    }

    return 0;
}
*/
