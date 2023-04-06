/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:54:18 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/06 19:06:27 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	parser(char **tokens)
{
	int		i;
	int		idx_err;
	char	*err_token;

	i = 0;
	idx_err = get_syntax_error_idx(tokens);
	if (idx_err != -2)
	{
		if (tokens[idx_err + 1] == NULL)
			err_token = ft_strdup("newline");
		else
			err_token = ft_strdup(tokens[idx_err + 1]);
		printf("bash: syntax error near unexpected token `%s'\n", err_token);
		g_minishell.status_code = 127;
		free(err_token);
		return (1);
	}
	while (tokens[i])
	{
		expand_token(tokens + i);
		i++;
	}
	g_minishell.status_code = 0;
	erase_empty_quotes_and_ext_quotes(tokens);
	return (0);
}
