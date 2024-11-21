/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:00:21 by mhegedus          #+#    #+#             */
/*   Updated: 2024/11/19 11:51:39 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

static int	to_positive(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static void	write_number_recursive(int n, int *char_count)
{
	char	c;

	if (n / 10)
		write_number_recursive(n / 10, char_count);
	c = to_positive(n % 10) + '0';
	*char_count += write(STDOUT_FILENO, &c, 1);
}

// prints integer n to stdout
// returns number of chars printed
int	print_int(int n)
{
	int	char_count;

	char_count = 0;
	if (n < 0)
		char_count += write(STDOUT_FILENO, "-", 1);
	write_number_recursive(n, &char_count);
	return (char_count);
}
/*
#include <stdlib.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_putnbr_fd(atoi(argv[1]), atoi(argv[2]));
	}
}
*/