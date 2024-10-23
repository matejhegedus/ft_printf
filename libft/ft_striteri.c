/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:38:46 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/01 21:48:17 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &(s[i]));
		i++;
	}
}
/*
#include <stdio.h>
void	test_f(unsigned int index, char *c)
{
	*c = *c + index;
}

int	main(void)
{
	char s[] = "This is a test string";
	ft_striteri(s, test_f);
	printf("%s\n", s);	
}
*/
