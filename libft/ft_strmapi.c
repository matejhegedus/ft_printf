/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:09:54 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/01 21:46:19 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	result_len;
	char			*result;
	unsigned int	i;

	result_len = ft_strlen(s);
	result = malloc(result_len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < result_len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
char	test_f(unsigned int index, char c)
{
	char result;

	result = c + index;
	return (result);
}

int	main(void)
{
	printf("%s\n", ft_strmapi("This is a test string", test_f));	
}
*/