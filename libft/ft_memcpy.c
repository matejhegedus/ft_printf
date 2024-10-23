/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:03:56 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/10 12:08:52 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
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
		printf("%s\n", (char *)ft_memcpy(dest, src, atoi(argv[3])));
	}
	else
	{
		char src[] = "ABCDEFGHIJKLMNOPQ";
		char dest[] = "alphabet!";
		printf("%s", (char *)ft_memcpy(dest, src, 4));
	}
}
*/
