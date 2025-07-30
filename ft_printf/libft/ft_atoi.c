/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:44:07 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/01/28 15:51:39 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Cadenas de prueba
    const char *str1 = "123";
    const char *str2 = "   -456";
    const char *str3 = "+789";
    const char *str4 = "42abc";
    const char *str5 = "  2147483647"; // valor máximo de int
    const char *str6 = "  -2147483648"; // valor mínimo de int
    const char *str7 = "  00001234";
    const char *str8 = "       ";

    // Pruebas
    printf("'%s' to int: %d\n", str1, ft_atoi(str1)); // Debería imprimir 123
    printf("'%s' to int: %d\n", str2, ft_atoi(str2)); // Debería  -456
    printf("'%s' to int: %d\n", str3, ft_atoi(str3)); // Debería imprimir 789
    printf("'%s' to int: %d\n", str4, ft_atoi(str4)); // Debería imprimir 42
    printf("'%s' to int: %d\n", str5, ft_atoi(str5)); // Debería 2147483647
    printf("'%s' to int: %d\n", str6, ft_atoi(str6)); // Debería -2147483648
    printf("'%s' to int: %d\n", str7, ft_atoi(str7)); // Debería  1234
    printf("'%s' to int: %d\n", str8, ft_atoi(str8)); // Debería imprimir 0

    return 0;
}
*/
