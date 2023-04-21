/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:54:18 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/21 18:30:53 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	is_empty_quote(char *str)
{
	if (*str == str[1])
		return (1);
	return (0);
}

static void	erase_external_quotes(char *str)
{
	int	last_pos;
	int	str_len;

	str_len = ft_strlen(str);
	ft_memmove(str, str + 1, str_len);
	last_pos = str_len - 2;
	ft_memset(str + last_pos, 0, 1);
}

static void	clear_subtokens(char **subtokens)
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

static int	print_invalid_syntax(int idx_err, char **tokens)
{
	char	*err_token;

	if (tokens[idx_err + 1] == NULL)
		err_token = ft_strdup("newline");
	else
		err_token = ft_strdup(tokens[idx_err + 1]);
	printf("bash: syntax error near unexpected token `%s'\n", err_token);
	g_minishell.status_code = 2;
	free(err_token);
	return (1);
}

void	remove_quotes2(char **tokens)
{
	int		i;
	char	**subtokens;

	i = 0;
	while (tokens[i])
	{
		if (ft_strcmp(tokens[i], ">") || ft_strcmp(tokens[i], "<") \
				|| ft_strcmp(tokens[i], ">>") || ft_strcmp(tokens[i], "<<"))
		{
			subtokens = get_subtokens(tokens[i], 0);
			clear_subtokens(subtokens);
			free(tokens[i]);
			tokens[i] = concat_subtokens(subtokens);
			free(subtokens);
		}
		i++;
	}
}

int	parser(char **tokens)
{
	int		i;
	int		idx_err;

	i = 0;
	idx_err = get_syntax_error_idx(tokens);
	if (idx_err != -2)
		return (print_invalid_syntax(idx_err, tokens));
	while (tokens[i])
	{
		expand_token(tokens + i);
		i++;
	}
	remove_quotes2(tokens);
	print_possible_redirect_error(tokens);
	return (0);
}
