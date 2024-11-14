/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:15:59 by mhegedus          #+#    #+#             */
/*   Updated: 2024/11/14 18:35:35 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_contains_plusminus(char *str)
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

int	ft_contains_duplicates(char *str, int len)
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

int	ft_strlen(char *str)
{
	int	char_count;

	char_count = 0;
	while (str[char_count] != '\0')
		char_count++;
	return (char_count);
}

void	ft_write_last_digit_rec(unsigned int nbr, char *base, int base_num)
{
	int		digit;
	char	c;

	digit = nbr % base_num;
	c = base[digit];
	if (nbr / base_num != 0)
		ft_write_last_digit_rec(nbr / base_num, base, base_num);
	write(1, &c, 1);
}

void	ft_putnbr_base_unsigned(unsigned int nbr, char *base)
{
	int	base_num;

	base_num = ft_strlen(base);
	if (base_num <= 1 || ft_contains_duplicates(base, base_num)
		|| ft_contains_plusminus(base))
		return ;
	ft_write_last_digit_rec(nbr, base, base_num);
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
