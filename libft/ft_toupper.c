/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:59:21 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/01/21 15:29:40 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 97) && (c <= 122))
	{
		c = c - 32;
		return (c);
	}
	else
	{
		return (c);
	}
}
/*
#include <stdio.h>
int main (void){
    
    char letter = 97;
    
    printf("%c",ft_toupper(letter));
    return (0);
}*/
