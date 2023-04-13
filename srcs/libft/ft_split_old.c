/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_old.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:35:48 by revieira          #+#    #+#             */
/*   Updated: 2023/04/13 15:21:22 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

char	**ft_split_old(const char *str, char c)
{
	int		i;
	char	**lst;
	size_t	curr_word_len;

	i = 0;
	if (!str)
		return (0);
	lst = (char **)ft_calloc(sizeof(char *), count_words(str, c) + 1);
	if (!lst)
		return (0);
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			if (!ft_strchr(str, c))
				curr_word_len = ft_strlen((char *)str);
			else
				curr_word_len = ft_strchr(str, c) - str;
			lst[i++] = ft_substr(str, 0, curr_word_len);
			str += curr_word_len;
		}
	}
	return (lst);
}
