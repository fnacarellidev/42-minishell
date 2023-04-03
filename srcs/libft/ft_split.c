/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:27:54 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/03 16:36:40 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	len_until_set(char const *s)
{
	int	count;

	count = 0;
	while (!ft_is_space(*s) && *s)
	{
		s++;
		count++;
	}
	return (count);
}

static int	number_of_words(char const *s)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (!ft_is_space(*s))
			count++;
		while (!ft_is_space(*s) && *s)
			s++;
		while (ft_is_space(*s) && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s)
{
	int		i;
	int		words;
	int		len_current_word;
	char	**splitted_string;

	i = 0;
	if (!s)
		return (NULL);
	words = number_of_words(s);
	splitted_string = ft_calloc(words + 1, sizeof(char *));
	while (*s && words != 0)
	{
		if (!ft_is_space(*s))
		{
			len_current_word = len_until_set(s);
			*(splitted_string + i) = ft_substr(s, 0, len_current_word);
			i++;
		}
		while (!ft_is_space(*s) && *s)
			s++;
		while (ft_is_space(*s) && *s)
			s++;
	}
	return (splitted_string);
}
