/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:42:32 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/10 12:42:11 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy_reverse(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0)
	{
		i--;
		((char *)dest)[i] = ((char *)src)[i];
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src < dest)
		ft_memcpy_reverse(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		char *dest = argv[1];
		char *src = argv[2];		
		printf("%s\n", (char *)ft_memmove(dest, src, atoi(argv[3])));
	}
	else
	{
		char str[] = "ABCDEFGHIJKLMNOPQ";
		char *dest = &(str[2]);
		char *src = &(str[0]);
		printf("src: %s\n", src);
		printf("dst: %s\n", dest);
		printf("res: %s", (char *)ft_memmove(dest, src, 4));
	}
}
*/
