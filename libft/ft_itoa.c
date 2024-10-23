/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:53:22 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/01 21:09:09 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_num_len(int n)
{
	int	result;

	if (n == 0)
		return (1);
	result = 0;
	while (n)
	{
		result++;
		n = n / 10;
	}
	return (result);
}

static int	to_positive(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		result_len;
	int		i;

	if (n >= 0)
		result_len = get_num_len(n) + 1;
	else
		result_len = get_num_len(n) + 2;
	result = malloc(result_len);
	if (result == NULL)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	if (n < 0)
		result[0] = '-';
	i = result_len - 1;
	result[i] = '\0';
	while (n)
	{
		i--;
		result[i] = to_positive(n % 10) + '0';
		n = n / 10;
	}
	return (result);
}
/*
#include <stdio.h>
int main (int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%s\n", ft_itoa(atoi(argv[1])));
	}
}
*/