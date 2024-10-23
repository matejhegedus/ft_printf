/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:19:40 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/10 12:42:44 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;

	if (n == 0)
		return (0);
	s1_uc = (unsigned char *)s1;
	s2_uc = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_uc[i] - s2_uc[i] != 0)
			return (s1_uc[i] - s2_uc[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("%d\n", ft_memcmp(argv[1], argv[2], atoi(argv[3])));
	}
	else
	{
		printf("1. %d\n", ft_memcmp("String", "String", 3));
		printf("2. %d\n", ft_memcmp("String", "StrABCDEFGH", 3));
		printf("3. %d\n", ft_memcmp("SZring", "String", 3));
		printf("4. %d\n", ft_memcmp("String", "", 3));
		printf("5. %d\n", ft_memcmp("", "String", 3));
		printf("6. %d\n", ft_memcmp("\n", "\b", 3));
		printf("7. %d\n", ft_memcmp("String", "String", 0));

		char s1[] = "r";
		char s3[] = "abcdefgh";
		char s2[] = "r";
		printf("8. %d\n", ft_memcmp(s1, s2, 1));
		printf("9. %d\n", ft_memcmp(s3, s2, 1));
	}
}
*/