/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:15:59 by mhegedus          #+#    #+#             */
/*   Updated: 2024/11/19 11:57:15 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf_utils.h" // for FD

static int	contains_plusminus(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

static int	contains_duplicates(char *str, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	write_last_digit_rec(unsigned int nbr, char *base, int base_num,
	int *char_count)
{
	int		digit;
	char	c;

	digit = nbr % base_num;
	c = base[digit];
	if (nbr / base_num != 0)
		write_last_digit_rec(nbr / base_num, base, base_num, char_count);
	*char_count += write(1, &c, STDOUT_FILENO);
}

// prints unsigned integer to stdout in given base
// base "0123456789" for decimal, "0123456789abcdef" for hexadecimal,
// "01" for binary etc.
// returns number of characters printed
int	print_uint_base(unsigned int nbr, char *base)
{
	int	base_num;
	int	char_count;

	char_count = 0;
	base_num = ft_strlen(base);
	if (base_num <= 1 || contains_duplicates(base, base_num)
		|| contains_plusminus(base))
		return (char_count);
	write_last_digit_rec(nbr, base, base_num, &char_count);
	return (char_count);
}
/*
#include <stdlib.h>
int	main(int argc, char **argv)
{
	if (argc >= 3)
		ft_putnbr_base(atoi(argv[1]), argv[2]);
	//ft_putnbr(123);
}
*/
