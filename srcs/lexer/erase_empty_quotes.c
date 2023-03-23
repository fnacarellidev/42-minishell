/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_empty_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:17:10 by revieira          #+#    #+#             */
/*   Updated: 2023/03/23 14:48:04 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static char	*find_subsequent_quotes(char *str)
{
	while (*str)
	{
		if ((*str == SINGLE_QUOTE || *str == DOUBLE_QUOTE) && str[1] == *str)
			return (str);
		str++;
	}
	return (NULL);
}

static void	erase_subsequent_quote(char *str)
{
	int	len_str;

	len_str = ft_strlen(str);
	if (str[2] == '\0')
	{
		str[0] = '\0';
		return ;
	}
	ft_memmove(str, str + 2, len_str - 2);
	str[len_str - 2] = '\0';
}

void	erase_empty_quotes(char *str)
{
	char	*empty_quotes;

	empty_quotes = find_subsequent_quotes(str);
	while (empty_quotes)
	{
		erase_subsequent_quote(empty_quotes);
		empty_quotes = find_subsequent_quotes(str);
	}
}
