/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:55:42 by mhegedus          #+#    #+#             */
/*   Updated: 2024/09/19 20:18:37 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%c %c", argv[1][0], (char)ft_tolower(argv[1][0]));
	}
}
*/