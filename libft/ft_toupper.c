/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:55:42 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/10 12:14:18 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%c %c", argv[1][0], (char)ft_toupper(argv[1][0]));
	}
}
*/