/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:03:40 by mhegedus          #+#    #+#             */
/*   Updated: 2024/11/18 13:50:44 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	write_number_recursive(unsigned int n, int fd)
{
	char	c;

	if (n / 10)
		write_number_recursive(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

// prints unsigned integer to file descriptor fd (for stdout, fd = 1)
void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
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