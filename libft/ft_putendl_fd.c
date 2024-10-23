/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:00:21 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/01 22:09:32 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &(s[i]), 1);
		i++;
	}
	write(fd, "\n", 1);
}
/*
#include <stdlib.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_putendl_fd(argv[1], atoi(argv[2]));
	}
}
*/
