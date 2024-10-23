/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:40:27 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/09 00:10:35 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	char_count;

	char_count = 0;
	while (s[char_count] != '\0')
		char_count++;
	return (char_count);
}

// #include <stdio.h>
// #include <string.h>
// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("%zu\n", ft_strlen(argv[1]));
// 		printf("%zu\n", strlen(argv[1]));
// 	}

// 	// const char *str = "\t";
// 	// printf("%zu\n", ft_strlen(str));
// 	// printf("%zu\n", strlen(str));
// }
