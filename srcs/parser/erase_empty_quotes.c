/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_empty_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:10:06 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/06 20:10:51 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	is_empty_quote(char *str)
{
	if (*str == str[1])
		return (1);
	return (0);
}

void	erase_external_quotes(char *str)
{
	int	last_pos;
	int	str_len;

	str_len = ft_strlen(str);
	ft_memmove(str, str + 1, str_len);
	last_pos = str_len - 2;
	ft_memset(str + last_pos, 0, 1);
}

void	clear_subtokens(char **subtokens)
{
	int	i;

	i = 0;
	while (subtokens[i])
	{
		if (is_quote(*subtokens[i]) && is_empty_quote(subtokens[i]))
			ft_memset(subtokens[i], 0, 2);
		else if (is_quote(*subtokens[i]))
			erase_external_quotes(subtokens[i]);
		i++;
	}
}

void	erase_empty_quotes_and_ext_quotes(char **tokens)
{
	int		i;
	char	quoted;
	char	**subtokens;

	i = 0;
	quoted = 0;
	while (tokens[i] != NULL)
	{
		subtokens = get_subtokens(tokens[i], 0);
		clear_subtokens(subtokens);
		free(tokens[i]);
		tokens[i] = concat_subtokens(subtokens);
		free(subtokens);
		i++;
	}
}
