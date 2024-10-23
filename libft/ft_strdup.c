/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:25:27 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/13 14:47:50 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_s;
	size_t	i;

	len = ft_strlen(s);
	new_s = malloc(sizeof(char) * (len + 1));
	if (new_s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
/*
#include <stdio.h>
int main(void)
{
	const char *s = "  This is a test String.";
	char *new_s = ft_strdup(s);

	printf("%s", new_s);
}
*/