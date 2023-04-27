/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:56:43 by revieira          #+#    #+#             */
/*   Updated: 2023/04/27 17:49:11 by revieira         ###   ########.fr       */
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

static void	close_backups(int stdin_backup, int stdout_backup)
{
	close(stdin_backup);
	close(stdout_backup);
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
		close_backups(stdin_backup, stdout_backup);
		builtin(cmd);
	}
	else
	{
		if (ft_strcmp(cmd.args[0], "exit") == 0)
		{
			close_backups(stdin_backup, stdout_backup);
			g_minishell.status_code = builtin(cmd);
		}
		g_minishell.status_code = builtin(cmd);
		dup2(stdin_backup, STDIN_FILENO);
		dup2(stdout_backup, STDOUT_FILENO);
		close_backups(stdin_backup, stdout_backup);
	}
}
