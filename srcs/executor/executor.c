/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:38:16 by revieira          #+#    #+#             */
/*   Updated: 2023/04/11 19:10:24 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	number_of_commands(char **tokens_without_redirects)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tokens_without_redirects[i])
	{
		if (ft_strcmp("|", tokens_without_redirects[i]) == 0)
			j++;
		i++;
	}
	return (j + 1);
}

static void	init_pipeline(char **tokens)
{
	int	mem;

	g_minishell.pipeline.number_of_cmds = number_of_commands(tokens);
	mem = g_minishell.pipeline.number_of_cmds;
	g_minishell.pipeline.commands = ft_calloc(sizeof(t_command), mem + 1);
}

void	executor(char **tokens)
{
	char	**new_tokens;

	if (validate_redirects(tokens) == 1)
	{
		g_minishell.status_code = 1;
		return ;
	}
	init_redirects(tokens);
	new_tokens = get_tokens_without_redirects(tokens);
	init_pipeline(new_tokens);
}
