/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:54:18 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/03 13:28:53 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	has_var_to_expands(char *token)
{
	if (ft_strchr(token, '$'))
		return (1);
	return (0);
}

void	check_need_expand(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (has_var_to_expands(tokens[i]))
			expand_vars(&tokens[i]);
		i++;
	}
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
		return (1);
	}
	check_need_expand(tokens);
	return (0);
}
