/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:37:55 by mhegedus          #+#    #+#             */
/*   Updated: 2024/11/14 19:21:51 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf_utils.h"

// void	print_conversion(char conv_c, void *arg)
// {

// }

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				write(1, "%", 1);
			if (str[i] == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
			}
			if (str[i] == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			if (str[i] == 'p')
			{
				write(1, "0x", 2);
				ft_putnbr_base_unsigned(va_arg(args, int), "0123456789abcdef");
			}
			if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			if (str[i] == 'u')
				ft_putnbr_unsigned_fd(va_arg(args, int), 1);
			if (str[i] == 'x')
				ft_putnbr_base_unsigned(va_arg(args, int), "0123456789abcdef");
			if (str[i] == 'X')
				ft_putnbr_base_unsigned(va_arg(args, int), "0123456789ABCDEF");
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (i);
}
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	printf   ("orig: %%c character '%c'\n", 't');
	ft_printf("my  : %%c character '%c'\n", 't');

	printf   ("orig: %%s string \"%s\"\n", "This is a test string");
	ft_printf("my  : %%s string \"%s\"\n", "This is a test string");

	void *ptr = malloc(20);
	printf   ("orig: %%p void * %p\n", ptr);
	ft_printf("my  : %%p void * %p\n", ptr);
	free(ptr);

	printf   ("orig: %%d decimal * %d\n", -123456);
	ft_printf("my  : %%d decimal * %d\n", -123456);

	printf   ("orig: %%i decimal * %i\n", -123456);
	ft_printf("my  : %%i decimal * %i\n", -123456);

	printf   ("orig: %%u unsigned decimal * %u\n", -123456);
	ft_printf("my  : %%u unsigned decimal * %u\n", -123456);

	printf   ("orig: %%x hexadecimal lowercase * %x\n", -1);
	ft_printf("my  : %%x hexadecimal lowercase * %x\n", -1);

	printf   ("orig: %%X hexadecimal uppercase * %X\n", -1);
	ft_printf("my  : %%X hexadecimal uppercase * %X\n", -1);
}
