/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:03:56 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/13 15:12:56 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

// #include <stdio.h>
// #include <strings.h>
// int	main(void)
// {
// 	char	*str_orig = "Nice";
// 	char	*str_my = "Nice";
// 	printf("Orig Before: %s\n", str_orig);
// 	bzero(str_orig, 4);
// 	printf("Orig After:  %s\n", str_orig);
// 	printf("My Before:   %s\n", str_my);
// 	ft_bzero(str_my, 4);
// 	printf("My After:    %s\n", str_my);
// }