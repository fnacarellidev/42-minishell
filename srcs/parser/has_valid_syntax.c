/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:07:54 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/27 18:22:24 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	is_preceeded_or_followed_by_metachar(char **tokens, int pos)
{
	if (is_meta_char(*tokens[pos - 1]) || is_meta_char(*tokens[pos + 1]))
		return (1);
	return (0);
}

static int	syntax_error_on_redirect(char *next_token)
{
	if ((next_token == NULL || is_meta_char(*next_token)))
	{
		minishell.status_code = 2;
		return (1);
	}
	return (0);
}

static int	syntax_error_on_pipe(char **tokens, int pos)
{
	if (pos == 0)
		return (-2);
	if (tokens[pos + 1] == NULL
			|| is_preceeded_or_followed_by_metachar(tokens, pos))
	{
		minishell.status_code = 2;
		return (1);
	}
	return (0);
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

static void	validate_unclosed_quotes(char **tokens)
{
	int		i;

	i = 0;
	while (tokens[i])
	{
		if (has_unclosed_quote(tokens[i]) != 0)
		{
			minishell.status_code = 2;
			break ;
		}
		i++;
	}
}

void	has_valid_syntax(char **tokens)
{
	validate_pipes(tokens);
	validate_redirects(tokens);
	validate_unclosed_quotes(tokens);
}
