/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:48:39 by mhegedus          #+#    #+#             */
/*   Updated: 2024/11/18 14:49:28 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_utils.h"
#include "libft/libft.h"

static int	ft_contains_plusminus(char *str)
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

static int	ft_contains_duplicates(char *str, int len)
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

static void	write_last_digit_long(unsigned long nbr, char *base, int base_num)
{
	int		digit;
	char	c;

	digit = nbr % base_num;
	c = base[digit];
	if (nbr / base_num != 0)
		write_last_digit_long(nbr / base_num, base, base_num);
	write(1, &c, 1);
}

static void	ft_putlong_base_unsigned(unsigned long nbr, char *base)
{
	int	base_num;

	base_num = ft_strlen(base);
	if (base_num <= 1 || ft_contains_duplicates(base, base_num)
		|| ft_contains_plusminus(base))
		return ;
	write_last_digit_long(nbr, base, base_num);
}

// prints the address of a pointer
void	ft_putptr_fd(void *ptr, int fd)
{
	if (ptr == NULL)
		ft_putstr_fd("(nil)", fd);
	else
	{
		write(1, "0x", 2);
		ft_putlong_base_unsigned((unsigned long)ptr, "0123456789abcdef");
	}
}
