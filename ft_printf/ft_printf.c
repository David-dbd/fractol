/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:31:50 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/03/22 18:18:55 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		counter;
	int		verify;

	va_start (args, format);
	counter = 0;
	verify = 0;
	len = ft_main_logic(args, format, counter, verify);
	if (len == -1)
		return (-1);
	va_end (args);
	return (len);
}

/*#include <stdio.h>

int main(void){
    
    char name[] = "David";
    int years = 242342334;
    char *ptr = name;
    char nul = 'K';
    int number;
    
    number = printf("Hola %s,   %X \n", "David", years);
    printf("%d \n",number);
    number = ft_printf("Hola %s, %X \n", "David", years);
    printf("%d \n",number);
    number =printf("Hi %s, are you %%%d old? \n",name, years);
    printf("%d \n",number);
    number =ft_printf("Hi %s, are you %%%d old? \n",name, years);
    printf("%d \n",number);
    number =printf("Hi %c, are  you %p old? \n",nul, ptr);
    printf("%d \n",number);
    number =ft_printf("Hi %c, are  you %p old? \n",nul, ptr);
    printf("%d",number);
    return (0);
}*/
