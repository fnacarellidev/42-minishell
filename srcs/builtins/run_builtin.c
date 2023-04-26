/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:56:43 by revieira          #+#    #+#             */
/*   Updated: 2023/04/26 15:09:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	handle_input(t_command cmd)
{
	if (cmd.input_fd != STDIN_FILENO)
		dup2(cmd.input_fd, STDIN_FILENO);
	else if (cmd.pipe[0] != 0)
		dup2(cmd.pipe[0], STDIN_FILENO);
}

static void	handle_output(t_command cmd)
{
	if (cmd.output_fd != STDOUT_FILENO)
		dup2(cmd.output_fd, STDOUT_FILENO);
	else if (cmd.pipe[1] != 0)
		dup2(cmd.pipe[1], STDOUT_FILENO);
}

void	run_builtin(t_command cmd, int (*builtin)(t_command cmd))
{
	int	stdin_backup;
	int	stdout_backup;

	stdin_backup = dup(STDIN_FILENO);
	stdout_backup = dup(STDOUT_FILENO);
	handle_input(cmd);
	handle_output(cmd);
	if (g_minishell.on_fork)
	{
		close_fds_in_child();
		close(stdin_backup);
		close(stdout_backup);
		builtin(cmd);
	}
	else
	{
		g_minishell.status_code = builtin(cmd);
		dup2(stdin_backup, STDIN_FILENO);
		dup2(stdout_backup, STDOUT_FILENO);
		close(stdin_backup);
		close(stdout_backup);
	}
}
