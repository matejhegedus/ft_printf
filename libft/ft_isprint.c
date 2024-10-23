/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:15:39 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/09 00:00:16 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%d\n", ft_isprint(atoi(argv[1])));
		printf("%d\n", isprint(atoi(argv[1])));
	}
}
*/