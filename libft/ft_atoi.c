/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:56:23 by mhegedus          #+#    #+#             */
/*   Updated: 2024/09/20 11:24:09 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

static int	digits_to_number(const char *str)
{
	int	power;
	int	result;
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	result = 0;
	power = 1;
	i = i - 1;
	while (i >= 0)
	{
		result += (str[i] - '0') * power;
		power *= 10;
		i--;
	}
	return (result);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	is_negative;
	int	result;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	is_negative = false;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			is_negative = true;
		i++;
	}
	result = digits_to_number(&nptr[i]);
	if (is_negative)
		return (-result);
	else
		return (result);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%d\n", ft_atoi(argv[1]));
	}
	// printf("%d\n", ft_atoi("\n \t\v\f\r---45679"));
}
*/
