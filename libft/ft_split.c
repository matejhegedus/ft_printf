/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhegedus <mhegedus@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:55:15 by mhegedus          #+#    #+#             */
/*   Updated: 2024/10/08 23:21:34 by mhegedus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_words(char const *s, char delimiter)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == delimiter)
			i++;
		if (s[i] && s[i] != delimiter)
		{
			count++;
			i++;
		}
		while (s[i] && s[i] != delimiter)
			i++;
	}
	return (count);
}

static size_t	get_word_len(char const *s, char delimiter)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != delimiter)
		i++;
	return (i);
}

static char const	*skip_delimiter(char const *s, char delimiter)
{
	while (*s == delimiter)
		s++;
	return (s);
}

static void	fill_word_array(char ***result, char const *s, size_t num_of_words,
		char delimiter)
{
	size_t	i;
	size_t	word_len;

	s = skip_delimiter(s, delimiter);
	i = 0;
	while (i < num_of_words)
	{
		word_len = get_word_len(s, delimiter);
		(*result)[i] = ft_substr(s, 0, word_len);
		if ((*result)[i] == NULL)
		{
			while (i-- >= 1)
			{
				free((*result)[i]);
				(*result)[i] = NULL;
			}
			free(*result);
			(*result) = NULL;
			return ;
		}
		s = s + word_len;
		s = skip_delimiter(s, delimiter);
		i++;
	}
	(*result)[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	num_of_words;
	char	**result;

	num_of_words = count_words(s, c);
	result = malloc((num_of_words + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	fill_word_array(&result, s, num_of_words, c);
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	char	**arr;

	arr = ft_split(" This    iS a STRING !!!    ", ' ');
	int i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
}
*/
