/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:39:14 by mhegedus          #+#    #+#             */
/*   Updated: 2024/11/19 11:54:30 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

int	print_int(int n);

int	print_uint_base(unsigned int nbr, char *base);

int	print_ptr(void *ptr);

int	print_str_or_null(char *s);

#endif