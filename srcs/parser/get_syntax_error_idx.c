/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_syntax_error_idx.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:07:54 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/27 14:57:54 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	syntax_error_on_redirect(char *next_token)
{
	if (next_token == NULL || is_redirect(next_token) \
			|| ft_strcmp(next_token, "|") == 0)
	{
		g_minishell.status_code = 2;
		return (1);
	}
	return (0);
}

static int	syntax_error_on_pipe(char **tokens, int pos)
{
	if (pos == 0)
		return (-2);
	if (tokens[pos + 1] == NULL || ft_strcmp(tokens[pos + 1], "|") == 0)
	{
		g_minishell.status_code = 2;
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

int	get_syntax_error_idx(char **tokens)
{
	int	i;
	int	before_pipe;

	i = 0;
	while (tokens[i] != NULL)
	{
		if (*tokens[i] == '|' && syntax_error_on_pipe(tokens, i))
		{
			before_pipe = syntax_error_on_pipe(tokens, i);
			if (before_pipe == -2)
				return (-1);
			return (i);
		}
		else if (is_redirect(tokens[i])
			&& syntax_error_on_redirect(tokens[i + 1]))
			return (i);
		else if (has_unclosed_quote(tokens[i]))
			return (i);
		i++;
	}
	return (-2);
}
