/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_n_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:18:03 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/20 14:04:13 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	handle_dups(t_command *prev, t_command *curr, t_command *next)
{
	if (!prev)
		dup2(curr->input_fd, STDIN_FILENO);
	else
	{
		if (curr->input_fd == STDIN_FILENO)
			dup2(prev->pipe[READ_END], STDIN_FILENO);
		else
			dup2(curr->input_fd, STDIN_FILENO);
	}
	if (!next)
		dup2(curr->output_fd, STDOUT_FILENO);
	else
	{
		if (curr->output_fd == STDOUT_FILENO)
			dup2(curr->pipe[WR_END], STDOUT_FILENO);
		else
			dup2(curr->output_fd, STDOUT_FILENO);
	}
}

static int	run_n_cmds(t_command *prev, t_command *curr, t_command *next)
{
	int	pid;

	if (next)
		pipe(curr->pipe);
	pid = fork();
	if (pid == 0)
	{
		if (curr->error)
			die_child(*curr);
		handle_dups(prev, curr, next);
		close_fds_in_child();
		execve(curr->bin_path, curr->args, g_minishell.envp);
	}
	return (pid);
}

int	handle_exec(int idx, t_command *curr)
{
	int			pid;
	t_command	prev;
	t_command	next;

	if (idx == 0)
	{
		next = g_minishell.commands[idx + 1];
		pid = run_n_cmds(NULL, curr, &next);
		close(g_minishell.commands[idx].pipe[WR_END]);
	}
	else if (idx == g_minishell.number_of_cmds - 1)
	{
		prev = g_minishell.commands[idx - 1];
		pid = run_n_cmds(&prev, curr, NULL);
		close(g_minishell.commands[idx - 1].pipe[READ_END]);
	}
	else
	{
		next = g_minishell.commands[idx + 1];
		prev = g_minishell.commands[idx - 1];
		pid = run_n_cmds(&prev, curr, &next);
		close(prev.pipe[READ_END]);
		close(curr->pipe[WR_END]);
	}
	return (pid);
}
