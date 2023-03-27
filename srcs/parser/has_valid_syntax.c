/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:07:54 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/27 15:02:39 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	is_preceeded_or_followed_by_metachar(char **tokens, int pos)
{
	if (is_meta_char(*tokens[pos - 1]) || is_meta_char(*tokens[pos + 1]))
		return (1);
	return (0);
}

static void	validate_redirects(char **tokens)
{
	int		i;

	i = 0;
	while (tokens[i])
	{
		if (!is_meta_char(*tokens[i]))
		{
			i++;
			continue ;
		}
		if (is_meta_char(*tokens[i]) && *tokens[i] != '|' && (tokens[i + 1] == NULL || is_meta_char(*tokens[i + 1])))
		{
			minishell.status_code = 2;
			break ;
		}
		i++;
	}
}

static void	validate_pipes(char **tokens)
{
	int		i;
	char	pipe;

	i = 0;
	pipe = '|';
	while (tokens[i])
	{
		if (*tokens[i] != pipe)
		{
			i++;
			continue ;
		}
		if (i == 0 || tokens[i + 1] == NULL
			|| is_preceeded_or_followed_by_metachar(tokens, i))
		{
			minishell.status_code = 2;
			break ;
		}
		i++;
	}
}

static int	has_unclosed_quote(char *token)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (token[i])
	{
		if (is_quote(token[i]) && quote == 0)
			quote = token[i];
		else if (is_quote(token[i]) && token[i] == quote)
			quote = 0;
		i++;
	}
	return (quote);
}
void	has_valid_syntax(char **tokens)
{
	validate_pipes(tokens);
	validate_redirects(tokens);
}
