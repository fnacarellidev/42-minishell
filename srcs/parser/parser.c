/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:54:18 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/20 15:43:26 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	print_invalid_syntax(int idx_err, char **tokens)
{
	char	*err_token;

	if (tokens[idx_err + 1] == NULL)
		err_token = ft_strdup("newline");
	else
		err_token = ft_strdup(tokens[idx_err + 1]);
	printf("bash: syntax error near unexpected token `%s'\n", err_token);
	g_minishell.status_code = 127;
	free(err_token);
	return (1);
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
	g_minishell.status_code = 0;
	return (0);
}
