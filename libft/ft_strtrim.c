/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:17:09 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/01/28 15:05:09 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	i = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	new_str = (char *)malloc((end - start + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (start < end)
	{
		new_str[i] = s1[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
#include <stdio.h>

int main(void)
{
    // Casos de prueba
    const char *str1 = "  Hello, World!  ";
    const char *set1 = " ";
    char *trimmed1 = ft_strtrim(str1, set1);
    if (trimmed1 != NULL)
    {
        printf("Trimmed1: '%s'\n", trimmed1); // Esperado: 'Hello, World!'
        free(trimmed1);
    }

    const char *str2 = "xxxyyyHello, World!yyyxxx";
    const char *set2 = "xyz";
    char *trimmed2 = ft_strtrim(str2, set2);
    if (trimmed2 != NULL)
    {
        printf("Trimmed2: '%s'\n", trimmed2); // Esperado: 'Hello, World!'
        free(trimmed2);
    }

    const char *str3 = "   ";
    const char *set3 = " ";
    char *trimmed3 = ft_strtrim(str3, set3);
    if (trimmed3 != NULL)
    {
        printf("Trimmed3: '%s'\n", trimmed3); // Esperado: ''
        free(trimmed3);
    }

    return 0;
}
*/
