/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_n_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:18:03 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/26 12:45:39 by revieira         ###   ########.fr       */
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
	g_minishell.on_fork = 1;
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		if (get_builtin_pos(curr->args[0]) != -1)
			run_builtin(*curr, g_minishell.builtins[get_builtin_pos(curr->args[0])]);
		if (curr->input_fd == -1 || curr->output_fd == -1)
			die_child(0, 1);
		if (curr->bin_path && curr->args[0])
		{
			handle_dups(prev, curr, next);
			close_fds_in_child();
			execve(curr->bin_path, curr->args, g_minishell.envp);
		}
		die_child(0, 0);
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
