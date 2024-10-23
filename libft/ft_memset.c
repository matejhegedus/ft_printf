/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:03:36 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/10 12:42:00 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char ** argv)
{
	char *s1;
	char *s2;

	if (argc == 5)
	{
		s1 = strdup(argv[1]);
		s2 = strdup(argv[1]);
		printf("ft_memset(\"%s\"[%d], %c, %d);:\n",
			argv[1], atoi(argv[3]), argv[2][0], atoi(argv[4]));
		// ft_memset(&s1[atoi(argv[3])], argv[2][0], atoi(argv[4]));
		memset(&s2[atoi(argv[3])], argv[2][0], atoi(argv[4]));
		printf("%s\n", s1);		
		printf("%s\n", s2);
	}
	else
	{
		char str[] = "alphabet!";
		ft_memset(&str[2], 'Y', 4);
		printf("%s\n", str);
	}
}
*/
