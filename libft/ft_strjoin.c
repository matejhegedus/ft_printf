/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:55:02 by mhegedus          #+#    #+#             */
/*   Updated: 2024/09/25 14:07:57 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	result = malloc(s1_len + ft_strlen(s2) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[i - s1_len])
	{
		result[i] = s2[i - s1_len];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
int main(void)
{
	const char *s1 = "first";
	const char *s2 = "second";

	printf("%s", ft_strjoin(s1, s2));
}
*/