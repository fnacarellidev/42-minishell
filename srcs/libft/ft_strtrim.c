/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:16:55 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/13 22:38:55 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	walk_end_of_string(const char *str, char const *set, int *match);
static void	walk_start_of_string(char const *str, char const *set, int *match);

static void	walk_start_of_string(char const *str, char const *set, int *match)
{
	size_t	i;
	size_t	j;
	size_t	set_len;

	i = 0;
	j = 0;
	set_len = ft_strlen(set);
	while (j < set_len)
	{
		if (*(str + i) == *(set + j))
		{
			j = 0;
			(*match)++;
			i++;
		}
		else
			j++;
	}
}

static void	walk_end_of_string(const char *str, char const *set, int *match)
{
	int		last_positions;
	size_t	j;
	size_t	set_len;

	j = 0;
	set_len = ft_strlen(set);
	last_positions = ft_strlen(str) - 1;
	while (j < set_len)
	{
		if (*(str + last_positions) == *(set + j))
		{
			j = 0;
			(*match)++;
			last_positions--;
		}
		else
			j++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_string;
	int		chars_to_be_removed;
	size_t	i;

	chars_to_be_removed = 0;
	walk_start_of_string(s1, set, &chars_to_be_removed);
	i = chars_to_be_removed;
	walk_end_of_string(s1, set, &chars_to_be_removed);
	trimmed_string = ft_substr(s1, i, ft_strlen(s1) - chars_to_be_removed);
	if (!trimmed_string)
		return (NULL);
	return (trimmed_string);
}
