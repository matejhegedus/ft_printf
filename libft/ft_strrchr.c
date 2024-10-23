/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:22:13 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/08 20:03:54 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*c_found;
	char	c_char;

	c_char = c % 128;
	i = 0;
	c_found = 0;
	while (s[i])
	{
		if (s[i] == c_char)
			c_found = ((char *)&(s[i]));
		i++;
	}
	if (c_char == '\0')
		c_found = (char *)&(s[i]);
	return (c_found);
}
/*
#include <stdio.h>
int main(void)
{
	const char *str = "Hello WoRLD!";

	printf("%s\n", str);
	printf("%s\n", ft_strrchr(str, 'o'));
}
*/
