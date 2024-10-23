/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:03:45 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/09 20:23:35 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1024);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%d\n", ft_isalpha(argv[1][0]));
		printf("%d\n", isalpha(argv[1][0]));
	}
	// printf("%d\n", ft_isalpha('A'));
	// printf("%d\n", ft_isalpha('Z'));
	// printf("%d\n", ft_isalpha('T'));
	// printf("%d\n", ft_isalpha('a'));
	// printf("%d\n", ft_isalpha('b'));
	// printf("%d\n", ft_isalpha('z'));
	// printf("%d\n", ft_isalpha('5'));
	// printf("%d\n", ft_isalpha('	'));
	// printf("%d\n", ft_isalpha(2147483647));
	// printf("%d\n", ft_isalpha(-2147483648));
	// printf("%d\n", ft_isalpha(66));
}
*/