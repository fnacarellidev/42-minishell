/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:57:20 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/24 21:16:49 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	remove_external_quotes(char *str)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (str[i])
	{
		if (is_quote(str[i]) && quote == '\0')
		{
			quote = str[i];
			ft_memmove(str + i, str + i + 1, ft_strlen(str + i));
		}
		else if (is_quote(str[i]) && str[i] == quote)
		{
			quote = 0;
			ft_memmove(str + i, str + i + 1, ft_strlen(str + i));
		}
		else
			i++;
	}
}

static void	fix_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		replace_between(tokens[i], DEL_ASCII, ' ');
		remove_external_quotes(tokens[i]);
		i++;
	}
}

char	**lexer(char *cmd)
{
	char	*str;
	char	**tokens;

	str = human_readable_cmd(cmd);
	replace_between(str, ' ', DEL_ASCII);
	tokens = ft_split(str, ' ');
	fix_tokens(tokens);
	free(str);
	return (tokens);
}
