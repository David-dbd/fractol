/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davdiaz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:55:13 by davdiaz-          #+#    #+#             */
/*   Updated: 2025/01/29 18:46:50 by davdiaz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static int	count(const char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
		{
			i++;
		}
		if (str[i] != '\0')
		{
			counter++;
			while (str[i] != '\0' && str[i] != c)
			{
				i++;
			}
		}
	}
	return (counter);
}

static int	copy_paste(const char *str, char *temp, char c, char **arr)
{
	int	i;
	int	x;
	int	temp_index;

	x = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
		{
			i++;
		}
		if (str[i] != '\0')
		{
			while (str[i] != '\0' && str[i] != c)
			{
				temp[temp_index++] = str[i++];
			}
			temp[temp_index] = '\0';
			arr[x++] = ft_strdup(temp);
			temp_index = 0;
		}
	}
	free (temp);
	return (x);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	char	*temp;
	int		i;
	int		x;

	x = 0;
	if (s[0] == '\0')
	{
		arr = (char **)malloc(1 * sizeof(char *));
		arr[0] = NULL;
		return (arr);
	}
	i = count(s, c);
	arr = (char **)malloc((i + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	temp = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!temp)
	{
		free (arr);
		return (NULL);
	}
	x = copy_paste(s, temp, c, arr);
	arr[x] = NULL;
	return (arr);
}
/*
#include <stdio.h>
int main() 
{ 
    char sub[] = "";
    char **result = ft_split(sub,' ');
    if (result) 
    {
        for (int i = 0; result[i] != NULL; i++) 
        {
            printf("%s ", result[i]); free(result[i]);
        }
free(result); 
    }
    return 0;
}
*/

/*
#include <stdio.h>
int main() 
{ 
    char sub[] = "";
    char **result = ft_split(sub,' ');
    if (result) 
    {
        for (int i = 0; result[i] != NULL; i++) 
        {
            printf("%s ", result[i]); free(result[i]);
        }
free(result); 
    }
    return 0;
}
*/
