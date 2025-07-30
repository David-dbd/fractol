/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:41:46 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/03/22 14:38:27 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static int	converter(unsigned long int n, int format, int base, char *digit)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (n != 0)
	{
		if (base == 16)
		{
			if (n % base > 9)
			{
				if (format == 1)
					digit[i++] = 'A' + ((n % base) - 10);
				else
					digit[i++] = 'a' + ((n % base) - 10);
			}
			else
				digit[i++] = n % base + '0';
		}
		else
			digit[i++] = n % base + '0';
		n = n / base;
		counter++;
	}
	return (counter);
}

static char	*turn_around(char *s)
{
	char	temp;
	int		i;
	int		len;
	int		j;

	i = 0;
	len = ft_strlen(s);
	j = len - 1;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	return (s);
}

char	*ft_itoa_base(unsigned long int n, int format, int base)
{
	char	*ptr;
	char	digit[20];
	int		counter;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	counter = converter(n, format, base, digit);
	ptr = (char *)malloc((counter + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	digit[counter] = '\0';
	turn_around(digit);
	i = 0;
	while (digit[i] != '\0')
	{
		ptr[i] = digit[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
