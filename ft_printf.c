/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:37:55 by mhegedus          #+#    #+#             */
/*   Updated: 2024/11/18 15:18:33 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf_utils.h"

void	print_conversion(char conv_c, va_list args)
{
	char	c;	

	if (conv_c == '%')
		ft_putchar_fd('%', FD);
	else if (conv_c == 'c')
		ft_putchar_fd(va_arg(args, char), FD);
	else if (conv_c == 's')
		ft_putstr_fd_null(va_arg(args, char *), FD);
	else if (conv_c == 'p')
		ft_putptr_fd(va_arg(args, void *), FD);
	else if (conv_c == 'd' || conv_c == 'i')
		ft_putnbr_fd(va_arg(args, int), FD);
	else if (conv_c == 'u')
		ft_putnbr_unsigned_fd(va_arg(args, int), FD);
	else if (conv_c == 'x')
		ft_putnbr_base_unsigned(va_arg(args, int), "0123456789abcdef");
	else if (conv_c == 'X')
		ft_putnbr_base_unsigned(va_arg(args, int), "0123456789ABCDEF");
}

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
			print_conversion(str[i], args);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (i);
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// int main(void)
// {
// 	printf("1:\n");
// 	printf   ("orig: %%c character '%c'\n", '@');
// 	ft_printf("my  : %%c character '%c'\n", '@');
// 	printf   ("orig: %%c character '%c'\n", 't');
// 	ft_printf("my  : %%c character '%c'\n", 't');
// 	printf   ("orig: %%c character '%c'\n", 123456);
// 	ft_printf("my  : %%c character '%c'\n", 123456);
// 	printf   ("orig: %%c character '%c'\n", 0);
// 	ft_printf("my  : %%c character '%c'\n", 0);
// 	printf   ("orig: %%c character '%c'\n", -25);
// 	ft_printf("my  : %%c character '%c'\n", -25);
// 	printf   ("orig: %%c character '%c'\n", INT_MAX);
// 	ft_printf("my  : %%c character '%c'\n", INT_MAX);
// 	printf   ("orig: %%c character '%c'\n", INT_MIN);
// 	ft_printf("my  : %%c character '%c'\n", INT_MIN);

// 	printf("\n");
// 	printf("2:\n");

// 	printf   ("orig: %%s string \"%s\"\n", "This is a test string");
// 	ft_printf("my  : %%s string \"%s\"\n", "This is a test string");
// 	printf   ("orig: %%s string \"%s\"\n", "");
// 	ft_printf("my  : %%s string \"%s\"\n", "");
// 	printf   ("orig: %%s string \"%s\"\n", "  !@$  !@  %\t\b\0");
// 	ft_printf("my  : %%s string \"%s\"\n", "  !@$  !@  %\t\b\0");
// 	printf   ("orig: %%s string \"%s\"\n", (char *)NULL);
// 	ft_printf("my  : %%s string \"%s\"\n", (char *)NULL);

// 	printf("\n");
// 	printf("3:\n");

// 	void *ptr = malloc(20);
// 	printf   ("orig: %%p void ptr %p\n", ptr);
// 	ft_printf("my  : %%p void ptr %p\n", ptr);
// 	free(ptr);
// 	printf   ("orig: %%p void ptr %p\n", NULL);
// 	ft_printf("my  : %%p void ptr %p\n", NULL);

// 	printf("\n");
// 	printf("4:\n");

// 	printf   ("orig: %%d decimal * %d\n", -123456);
// 	ft_printf("my  : %%d decimal * %d\n", -123456);
// 	printf   ("orig: %%d decimal * %d\n", INT_MAX);
// 	ft_printf("my  : %%d decimal * %d\n", INT_MAX);
// 	printf   ("orig: %%d decimal * %d\n", INT_MIN);
// 	ft_printf("my  : %%d decimal * %d\n", INT_MIN);
// 	printf   ("orig: %%d decimal * %d\n", 0);
// 	ft_printf("my  : %%d decimal * %d\n", 0);

// 	printf("\n");
// 	printf("5:\n");

// 	printf   ("orig: %%i decimal * %i\n", -123456);
// 	ft_printf("my  : %%i decimal * %i\n", -123456);
// 	printf   ("orig: %%i decimal * %i\n", INT_MAX);
// 	ft_printf("my  : %%i decimal * %i\n", INT_MAX);
// 	printf   ("orig: %%i decimal * %i\n", INT_MIN);
// 	ft_printf("my  : %%i decimal * %i\n", INT_MIN);
// 	printf   ("orig: %%i decimal * %i\n", 0);
// 	ft_printf("my  : %%i decimal * %i\n", 0);

// 	printf("\n");
// 	printf("6:\n");

// 	printf   ("orig: %%u unsigned decimal * %u\n", -123456);
// 	ft_printf("my  : %%u unsigned decimal * %u\n", -123456);
// 	printf   ("orig: %%u unsigned decimal * %u\n", INT_MAX);
// 	ft_printf("my  : %%u unsigned decimal * %u\n", INT_MAX);
// 	printf   ("orig: %%u unsigned decimal * %u\n", UINT_MAX);
// 	ft_printf("my  : %%u unsigned decimal * %u\n", UINT_MAX);
// 	printf   ("orig: %%u unsigned decimal * %u\n", INT_MIN);
// 	ft_printf("my  : %%u unsigned decimal * %u\n", INT_MIN);
// 	printf   ("orig: %%u unsigned decimal * %u\n", -1);
// 	ft_printf("my  : %%u unsigned decimal * %u\n", -1);
// 	printf   ("orig: %%u unsigned decimal * %u\n", 0);
// 	ft_printf("my  : %%u unsigned decimal * %u\n", 0);

// 	printf("\n");
// 	printf("7:\n");

// 	printf   ("orig: %%x hexadecimal lowercase * %x\n", -1);
// 	ft_printf("my  : %%x hexadecimal lowercase * %x\n", -1);
// 	printf   ("orig: %%x hexadecimal lowercase * %x\n", INT_MAX);
// 	ft_printf("my  : %%x hexadecimal lowercase * %x\n", INT_MAX);
// 	printf   ("orig: %%x hexadecimal lowercase * %x\n", UINT_MAX);
// 	ft_printf("my  : %%x hexadecimal lowercase * %x\n", UINT_MAX);
// 	printf   ("orig: %%x hexadecimal lowercase * %x\n", INT_MIN);
// 	ft_printf("my  : %%x hexadecimal lowercase * %x\n", INT_MIN);

// 	printf("\n");
// 	printf("8:\n");

// 	printf   ("orig: %%X hexadecimal uppercase * %X\n", -1);
// 	ft_printf("my  : %%X hexadecimal uppercase * %X\n", -1);
// 	printf   ("orig: %%X hexadecimal uppercase * %X\n", INT_MAX);
// 	ft_printf("my  : %%X hexadecimal uppercase * %X\n", INT_MAX);
// 	printf   ("orig: %%X hexadecimal uppercase * %X\n", UINT_MAX);
// 	ft_printf("my  : %%X hexadecimal uppercase * %X\n", UINT_MAX);
// 	printf   ("orig: %%X hexadecimal uppercase * %X\n", INT_MIN);
// 	ft_printf("my  : %%X hexadecimal uppercase * %X\n", INT_MIN);
// }
