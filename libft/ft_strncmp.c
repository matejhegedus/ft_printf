/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:59:08 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/13 15:30:18 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)(s1[i]) - (unsigned char)(s2[i]) != 0)
		{
			if ((unsigned char)(s1[i]) == '\0')
				return (-1);
			if ((unsigned char)(s2[i]) == '\0')
				return (1);
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		}
		else if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	printf("0.Orig %d\n", strncmp("stringlonger", "stringlong", 20));
// 	printf("0.mY   %d\n", ft_strncmp("stringlonger", "stringlong", 20));

// 	printf("1. %d\n", ft_strncmp("String", "String", 3));
// 	printf("2. %d\n", ft_strncmp("String", "StrABCDEFGH", 3));
// 	printf("3. %d\n", ft_strncmp("SZring", "String", 3));
// 	printf("4. %d\n", ft_strncmp("String", "", 3));
// 	printf("5. %d\n", ft_strncmp("", "String", 3));
// 	printf("6. %d\n", ft_strncmp("\n", "\b", 3));
// 	printf("7. %d\n", ft_strncmp("String", "String", 0));

// 	char s1[] = "r";
// 	char s3[] = "abcdefgh";
// 	char s2[] = "r";
// 	printf("8. %d\n", ft_strncmp(s1, s2, 3));
// 	printf("9. %d\n", ft_strncmp(s3, s2, 3));
// }