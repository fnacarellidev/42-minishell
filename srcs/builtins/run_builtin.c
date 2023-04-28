/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:56:43 by revieira          #+#    #+#             */
/*   Updated: 2023/04/28 10:21:28 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void	handle_input(t_command cmd, int *fd)
{
	if (cmd.input_fd != STDIN_FILENO)
		*fd = cmd.input_fd;
	else if (cmd.pipe[0] != 0)
		*fd = cmd.pipe[0];
}

void	handle_output(t_command cmd, int *fd)
{
	if (cmd.output_fd != STDOUT_FILENO)
		*fd = cmd.output_fd;
	else if (cmd.pipe[1] != 0)
		*fd = cmd.pipe[1];
}

void	run_builtin(t_command cmd, int (*builtin)(t_command cmd))
{
	if (g_minishell.on_fork)
		builtin(cmd);
	else
	{
		if (ft_strcmp(cmd.args[0], "exit") == 0)
			g_minishell.status_code = builtin(cmd);
		g_minishell.status_code = builtin(cmd);
	}
}
