/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:54:18 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/28 11:22:07 by fnacarel         ###   ########.fr       */
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
	g_minishell.status_code = 2;
	free(err_token);
	return (1);
}

static int	count_null(int size, char **tokens)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (tokens[i] == NULL)
			count++;
		i++;
	}
	return (count);
}

static char	**remove_null(int size, char **tokens)
{
	int		i;
	int		j;
	int		null_pos;
	char	**new_tokens;

	i = 0;
	j = 0;
	null_pos = count_null(size, tokens);
	new_tokens = ft_calloc(sizeof(char *), size - null_pos + 1);
	while (i < size)
	{
		if (tokens[i])
		{
			new_tokens[j] = ft_strdup(tokens[i]);
			j++;
		}
		i++;
	}
	ft_free_matrix_size_n((void **)tokens, size);
	return (new_tokens);
}

int	parser(char ***tokens)
{
	int		i;
	int		idx_err;
	int		size;

	i = 0;
	idx_err = get_syntax_error_idx(*tokens);
	if (idx_err != -2)
		return (print_invalid_syntax(idx_err, *tokens));
	size = ft_count_matrix((void **)*tokens);
	while ((*tokens)[i])
	{
		expand_token((*tokens) + i);
		i++;
	}
	if (count_null(size, *tokens) != 0)
		*tokens = remove_null(size, *tokens);
	return (0);
}
