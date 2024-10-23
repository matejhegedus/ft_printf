/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:15:26 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/13 14:10:20 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	find_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			return (i);
		i++;
	}
	return (i);
}

static size_t	find_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;
	size_t	result_len;

	start = find_start(s1, set);
	end = find_end(s1, set);
	if (end < start)
		result_len = 0;
	else
		result_len = end - start + 1;
	result = ft_substr(s1, start, result_len);
	return (result);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		char *s1 = argv[1];
		char *result = ft_strtrim(s1, argv[2]);
		printf("%s\n", result);
	}
	else
	{
		char s1[] = "abcdba";
		char *result = ft_strtrim(s1, "acb");
		printf("%s\n", result);
	}
}
*/