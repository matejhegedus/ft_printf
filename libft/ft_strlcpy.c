/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:27:40 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/06 21:43:33 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	str_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (str_len(src));
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (str_len(src));
}
/*
#include <stdio.h>
int	main(void)
{
	char src[] = "String1!";
	char dest[] = "A longer string.";
	
	printf("src: %s\ndest: %s\n", src, dest);
	ft_strlcpy(dest, src, 5);
	printf("src: %s\ndest: %s\n", src, dest);
	ft_strlcpy(dest, src, 9);
    printf("src: %s\ndest: %s\n", src, dest);
	ft_strlcpy(dest, src, 12);
    printf("src: %s\ndest: %s\n", src, dest);
	int i = 0;
	while (i < 16)
	{
		printf("%c", dest[i]);
		i++;
	}
}
*/