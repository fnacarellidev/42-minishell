/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:27:54 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/13 21:51:19 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	number_of_words(char const *s, char c);
static int	len_until_set(char const *s, char c);

static int	len_until_set(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != c && *s)
	{
		s++;
		count++;
	}
	return (count);
}

static int	number_of_words(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s != c)
			count++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted_string;
	int		words;
	int		i;
	int		len_current_word;

	i = 0;
	words = number_of_words(s, c);
	if (words < 0)
		return (NULL);
	splitted_string = ft_calloc(words + 1, sizeof(char *));
	while (*s && words != 0)
	{
		if (*s != c)
		{
			len_current_word = len_until_set(s, c);
			*(splitted_string + i) = ft_substr(s, 0, len_current_word);
			i++;
		}
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (splitted_string);
}
