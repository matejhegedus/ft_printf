/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:37:55 by mhegedus          #+#    #+#             */
/*   Updated: 2024/11/21 18:34:51 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf_utils.h"

int	print_conversion(char conv_c, va_list args)
{
	char	c;

	if (conv_c == '%')
		return (write(STDOUT_FILENO, "%", 1));
	else if (conv_c == 'c')
	{
		c = va_arg(args, int);
		return (write(STDOUT_FILENO, &c, 1));
	}
	else if (conv_c == 's')
		return (print_str_or_null(va_arg(args, char *)));
	else if (conv_c == 'p')
		return (print_ptr(va_arg(args, void *)));
	else if (conv_c == 'd' || conv_c == 'i')
		return (print_int(va_arg(args, int)));
	else if (conv_c == 'u')
		return (print_uint_base(va_arg(args, int), "0123456789"));
	else if (conv_c == 'x')
		return (print_uint_base(va_arg(args, int), "0123456789abcdef"));
	else if (conv_c == 'X')
		return (print_uint_base(va_arg(args, int), "0123456789ABCDEF"));
	else
		return (-1);
}

// replicates the function printf()
// supports conversions %cspdiuxX
// returns the number of characters printed or -1 if error is encountered
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		char_count;
	int		print_count;

	if (str == NULL)
		return (-1);
	va_start(args, str);
	char_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_count = print_conversion(str[++i], args);
			if (print_count == -1)
				return (-1);
			char_count += print_count;
		}
		else
			char_count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (char_count);
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// int main(void)
// {
// 	int i;

// 	i = printf   ("%%%% %c%c%c%c: This is a %s,\nnumbers %d%i, pointer: %p, \
// hex: %x or %X", 't', 'e', 's', 't', "test string", -123, -234,
// (void *)"string", 123456, 123456);
// 	fflush(stdout);
// 	printf(", returns %d\n", i);	
// 	i = ft_printf("%%%% %c%c%c%c: This is a %s,\nnumbers %d%i, pointer: %p, \
// hex: %x or %X", 't', 'e', 's', 't', "test string", -123, -234,
// (void *)"string", 123456, 123456);
// 	printf(", returns %d\n", i);

// 	// 1 %c
// 	printf("1:\n");
// 	i = printf   ("orig: %%c character '%c'", '@');
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%c character '%c'", '@');
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%c character '%c'", 't');
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%c character '%c'", 't');
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%c character '%c'", 123456);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%c character '%c'", 123456);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%c character '%c'", 0);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%c character '%c'", 0);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%c character '%c'", -25);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%c character '%c'", -25);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%c character '%c'", INT_MAX);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%c character '%c'", INT_MAX);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%c character '%c'", INT_MIN);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%c character '%c'", INT_MIN);
// 	printf(", returns %d\n", i);

// 	// 2 %s
// 	printf("\n");
// 	printf("2:\n");

// 	i = printf   ("orig: %%s string \"%s\"", "This is a test string");
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%s string \"%s\"", "This is a test string");
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%s string \"%s\"", "");
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%s string \"%s\"", "");
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%s string \"%s\"", "  !@$  !@  %\t\b\0");
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%s string \"%s\"", "  !@$  !@  %\t\b\0");
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%s string \"%s\"", (char *)NULL);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%s string \"%s\"", (char *)NULL);
// 	printf(", returns %d\n", i);

// 	// 3 %p
// 	printf("\n");
// 	printf("3:\n");

// 	void *ptr = malloc(20);
// 	i = printf   ("orig: %%p void ptr %p", ptr);
// 	printf(", returns %d\n", i);

// 	i = ft_printf("my  : %%p void ptr %p", ptr);
// 	printf(", returns %d\n", i);
// 	free(ptr);

// 	int n = INT_MAX;
// 	i = printf   ("orig: %%p void ptr %p", &n);
// 	printf(", returns %d\n", i);

// 	i = ft_printf("my  : %%p void ptr %p", &n);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%p void ptr %p", NULL);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%p void ptr %p", NULL);
// 	printf(", returns %d\n", i);

// 	// 4 %d
// 	printf("\n");
// 	printf("4:\n");

// 	i = printf   ("orig: %%d decimal %d", -123456);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%d decimal %d", -123456);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%d decimal %d", INT_MAX);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%d decimal %d", INT_MAX);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%d decimal %d", INT_MIN);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%d decimal %d", INT_MIN);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%d decimal %d", 0);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%d decimal %d", 0);
// 	printf(", returns %d\n", i);

// 	// 5 %i
// 	printf("\n");
// 	printf("5:\n");

// 	i = printf   ("orig: %%i decimal %i", -123456);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%i decimal %i", -123456);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%i decimal %i", INT_MAX);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%i decimal %i", INT_MAX);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%i decimal %i", INT_MIN);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%i decimal %i", INT_MIN);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%i decimal %i", 0);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%i decimal %i", 0);
// 	printf(", returns %d\n", i);

// 	// 6 %u
// 	printf("\n");
// 	printf("6:\n");

// 	i = printf   ("orig: %%u unsigned decimal %u", -123456);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%u unsigned decimal %u", -123456);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%u unsigned decimal %u", INT_MAX);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%u unsigned decimal %u", INT_MAX);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%u unsigned decimal %u", UINT_MAX);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%u unsigned decimal %u", UINT_MAX);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%u unsigned decimal %u", INT_MIN);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%u unsigned decimal %u", INT_MIN);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%u unsigned decimal %u", -1);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%u unsigned decimal %u", -1);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%u unsigned decimal %u", 0);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%u unsigned decimal %u", 0);
// 	printf(", returns %d\n", i);

// 	// 7 %x
// 	printf("\n");
// 	printf("7:\n");

// 	i = printf   ("orig: %%x hexadecimal lowercase %x", -1);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%x hexadecimal lowercase %x", -1);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%x hexadecimal lowercase %x", INT_MAX);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%x hexadecimal lowercase %x", INT_MAX);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%x hexadecimal lowercase %x", UINT_MAX);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%x hexadecimal lowercase %x", UINT_MAX);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%x hexadecimal lowercase %x", INT_MIN);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%x hexadecimal lowercase %x", INT_MIN);
// 	printf(", returns %d\n", i);

// 	// 8 %X
// 	printf("\n");
// 	printf("8:\n");

// 	i = printf   ("orig: %%X hexadecimal uppercase %X", -1);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%X hexadecimal uppercase %X", -1);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%X hexadecimal uppercase %X", INT_MAX);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%X hexadecimal uppercase %X", INT_MAX);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%X hexadecimal uppercase %X", UINT_MAX);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%X hexadecimal uppercase %X", UINT_MAX);
// 	printf(", returns %d\n", i);

// 	i = printf   ("orig: %%X hexadecimal uppercase %X", INT_MIN);
// 	printf(", returns %d\n", i);
// 	i = ft_printf("my  : %%X hexadecimal uppercase %X", INT_MIN);
// 	printf(", returns %d\n", i);

// 	// 9 errors
// 	printf("\n");
// 	printf("9 errors:\n");
// 	i = printf   (NULL);
// 	printf("returns %d\n", i);
// 	i = ft_printf(NULL);
// 	printf("returns %d\n", i);

// 	// i = printf   ("%   ");
// 	// printf("returns %d\n", i);
// 	i = ft_printf("%   ");
// 	printf("returns %d\n", i);

// 	// i = printf   ("%b");
// 	// printf("returns %d\n", i);
// 	i = ft_printf("%b");
// 	printf("returns %d\n", i);

// 	// i = printf   ("%d%", 123);
// 	// printf("returns %d\n", i);
// 	i = ft_printf("%d%", 123);
// 	printf("returns %d\n", i);
// }
