/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:54:18 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/29 19:57:10 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	has_var_to_expands(char *token)
{
	char	*tmp;

	tmp = ft_strchr(token, '$');
	if (tmp)
		return (1);
	return (0);
}

int	parser(char **tokens)
{
	int		idx_err;
	char	*err_token;

	idx_err = get_syntax_error_idx(tokens);
	if (idx_err != -2)
	{
		if (tokens[idx_err + 1] == NULL)
			err_token = ft_strdup("newline");
		else
			err_token = ft_strdup(tokens[idx_err + 1]);
		printf("bash: syntax error near unexpected token `%s'\n", err_token);
		free(err_token);
	}
	return (0);
}
