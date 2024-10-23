/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:55:36 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/10 11:47:22 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// returns 1 if multiplying the 2 numbers results in an overflow
// else returns 0
static char	is_multiply_overflow(size_t nmemb, size_t size)
{
	if (nmemb > 0 && size > __SIZE_MAX__ / nmemb)
		return (1);
	if (size > 0 && nmemb > __SIZE_MAX__ / size)
		return (1);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (is_multiply_overflow(nmemb, size))
		return (NULL);
	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((char *)mem)[i] = 0;
		i++;
	}
	return (mem);
}
/*
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int *arr = ft_calloc(atoi(argv[1]), atoi(argv[2]));
		for (int i = 0; i < atoi(argv[2]); i++)
		{
			for (int j = 0; j < atoi(argv[1]); j++)
			{
				printf("%c", ((char *)arr)[i * atoi(argv[1]) + j] + '0');
			}
			printf("\n");
		}
	}
	else
	{
		int *arr;
		arr = ft_calloc(sizeof(int), 12);
		for (int i = 0; i < 12; i++)
		{
			printf("%d\n", arr[i]);
		}
	}
}
*/
