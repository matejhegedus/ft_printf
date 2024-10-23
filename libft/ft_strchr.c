/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:22:13 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/08 20:03:35 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	c_char;

	c_char = c % 128;
	i = 0;
	while (s[i])
	{
		if (s[i] == c_char)
			return ((char *)&(s[i]));
		i++;
	}
	if (c_char == '\0')
		return ((char *)&(s[i]));
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	const char *str = "Hello WoRLD!";

	printf("%s\n", str);
	printf("%s\n", strchr(str, 'o' + 256));
	printf("%s\n", ft_strchr(str, 'o' + 256));
}
*/