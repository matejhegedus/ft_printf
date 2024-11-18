/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:39:14 by mhegedus          #+#    #+#             */
/*   Updated: 2024/11/18 15:16:38 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# ifndef FD
#  define FD 1
# endif

// ft_putnbr_unsigned_fd.c
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);

// ft_putnbr_base_unsigned.c
void	ft_putnbr_base_unsigned(unsigned int nbr, char *base);

// ft_putptr_fd.c
void	ft_putptr_fd(void *ptr, int fd);

// ft_putstr_fd_null.c
void	ft_putstr_fd_null(char *s, int fd);

#endif