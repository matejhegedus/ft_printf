/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:48:39 by mhegedus          #+#    #+#             */
/*   Updated: 2024/11/19 11:56:43 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_utils.h"
#include "libft/libft.h"

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

static void	write_last_digit_long(unsigned long nbr, char *base, int base_num,
	int *char_count)
{
	int		digit;
	char	c;

	digit = nbr % base_num;
	c = base[digit];
	if (nbr / base_num != 0)
		write_last_digit_long(nbr / base_num, base, base_num, char_count);
	*char_count += write(1, &c, 1);
}

static int	print_ulong_base(unsigned long nbr, char *base)
{
	int	base_num;
	int	char_count;

	char_count = 0;
	base_num = ft_strlen(base);
	if (base_num <= 1 || contains_duplicates(base, base_num)
		|| contains_plusminus(base))
		return (char_count);
	write_last_digit_long(nbr, base, base_num, &char_count);
	return (char_count);
}

// prints the address of a pointer
int	print_ptr(void *ptr)
{
	int	char_count;

	char_count = 0;
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", STDOUT_FILENO);
		char_count = ft_strlen("(nil)");
	}
	else
	{
		char_count += write(1, "0x", 2);
		char_count += print_ulong_base((unsigned long)ptr, "0123456789abcdef");
	}
	return (char_count);
}
