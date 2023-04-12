/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:58:29 by revieira          #+#    #+#             */
/*   Updated: 2023/04/12 16:58:51 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void	ft_free_commands(void)
{
	int	i;
	int	args;

	i = 0;
	args = g_minishell.number_of_cmds;
	close_fds();
	while (i < args)
	{
		ft_free_matrix((void **)g_minishell.commands[i].args);
		i++;
	}
	free(g_minishell.commands);
	g_minishell.commands = NULL;
}
