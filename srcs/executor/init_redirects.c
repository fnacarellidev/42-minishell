/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:06:37 by revieira          #+#    #+#             */
/*   Updated: 2023/04/20 19:19:02 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	fill_fds(t_command *cmd)
{
	int		i;
	int		heredoc_status;

	i = 0;
	heredoc_status = 0;
	cmd->input_fd = 0;
	cmd->output_fd = 1;
	while (cmd->args[i])
	{
		if (ft_strcmp("<<", cmd->args[i]) == 0)
			heredoc_status = heredoc(cmd, cmd->args[++i]);
		else if (ft_strcmp("<", cmd->args[i]) == 0)
			swap_stream_fd("input", cmd, open(cmd->args[++i], O_RDONLY));
		else if (ft_strcmp(">", cmd->args[i]) == 0)
			swap_stream_fd("output", cmd, open(cmd->args[++i], O_WRONLY));
		else if (ft_strcmp(">>", cmd->args[i]) == 0)
			swap_stream_fd("output", cmd, open(cmd->args[++i], \
				O_WRONLY | O_APPEND));
		if (heredoc_status != 0)
		{
			g_minishell.heredoc.heredoc_exited = 1;
			return ;
		}
		i++;
	}
}

void	init_redirects(void)
{
	int	i;
	int	args;

	i = 0;
	args = g_minishell.number_of_cmds;
	while (i < args && !g_minishell.heredoc.heredoc_exited)
	{
		fill_fds(&g_minishell.commands[i]);
		i++;
	}
}
