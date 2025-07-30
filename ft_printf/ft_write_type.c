/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:08:06 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/03/21 18:55:14 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int	ft_write_type(int len, char *result)
{
	len = ft_strlen(result);
	ft_putstr(result);
	free (result);
	return (len);
}
