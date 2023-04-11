/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:38:16 by revieira          #+#    #+#             */
/*   Updated: 2023/04/11 19:01:06 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	number_of_commands(char **tokens_without_redirects)
{
	int	i;
	int	j;

	while (tokens_without_redirects[i])
	{
		if (ft_strcmp("|", tokens_without_redirects[i]) == 0)
			j++;
		i++;
	}
	return (j + 1);
}
void	executor(char **tokens)
{
	if (validate_redirects(tokens) == 1)
	{
		g_minishell.status_code = 1;
		return ;
	}
	init_redirects(tokens);
}
