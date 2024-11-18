/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_null.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:08:47 by mhegedus          #+#    #+#             */
/*   Updated: 2024/11/18 15:11:27 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_putstr_fd_null(char *s, int fd)
{
	if (s == NULL)
		ft_putstr_fd("(null)", fd);
	else
		ft_putstr_fd(s, fd);
}
