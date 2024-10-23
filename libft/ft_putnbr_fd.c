/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:00:21 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/08 01:08:33 by mhegedus         ###   ########.fr       */
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

static void	write_number_recursive(int n, int fd)
{
	char	c;

	if (n / 10)
		write_number_recursive(n / 10, fd);
	c = to_positive(n % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	write_number_recursive(n, fd);
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