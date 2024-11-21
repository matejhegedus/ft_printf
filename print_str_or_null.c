/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_or_null.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:08:47 by mhegedus          #+#    #+#             */
/*   Updated: 2024/11/19 11:51:10 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h> // for STDOUT_FILENO

// prints string to stdout or the string "(null)" if *s == NULL
// returns number of chars printed
int	print_str_or_null(char *s)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", STDOUT_FILENO);
		return (ft_strlen("(null)"));
	}
	else
	{
		ft_putstr_fd(s, STDOUT_FILENO);
		return (ft_strlen(s));
	}
}
