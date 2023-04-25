/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:38:16 by revieira          #+#    #+#             */
/*   Updated: 2023/04/25 20:10:41 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	init_executor(char **tokens)
{
	init_commands(tokens, 0);
	ft_free_matrix((void **)tokens);
	remove_quotes();
	init_redirects();
	remove_redirects();
	update_number_of_args();
	init_bin_path();
}

static void	run_builtin(t_command cmd, int (*builtin)(t_command cmd))
{
	int	stdin_backup;
	int	stdout_backup;

	stdin_backup = dup(STDIN_FILENO);
	stdout_backup = dup(STDOUT_FILENO);
	if (cmd.input_fd != STDIN_FILENO)
		dup2(cmd.input_fd, STDIN_FILENO);
	if (cmd.output_fd != STDOUT_FILENO)
		dup2(cmd.output_fd, STDOUT_FILENO);
	g_minishell.status_code = builtin(cmd);
	dup2(stdin_backup, STDIN_FILENO);
	dup2(stdout_backup, STDOUT_FILENO);
}

static int	run_single_cmd(t_command cmd)
{
	int	pid;

	if (get_builtin_pos(cmd.args[0]) != -1)
	{
		run_builtin(cmd, g_minishell.builtins[get_builtin_pos(cmd.args[0])]);
		return (-1);
	}
	pid = fork();
	g_minishell.on_fork = 1;
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		if (cmd.error && get_builtin_pos(cmd.args[0]) == -1)
			die_child(0, cmd.error);
		if (cmd.input_fd == -1 || cmd.output_fd == -1)
			die_child(0, 1);
		dup2(cmd.input_fd, 0);
		dup2(cmd.output_fd, 1);
		close_fds_in_child();
		execve(cmd.bin_path, cmd.args, g_minishell.envp);
	}
	return (pid);
}

static void	loop_wait(int pid, int *status)
{
	int	i;
	int	size;

	i = 0;
	size = g_minishell.number_of_cmds;
	waitpid(pid, status, 0);
	while (i < size - 1)
	{
		wait(NULL);
		i++;
	}
	if (WIFEXITED(*status))
		g_minishell.status_code = WEXITSTATUS(*status);
	else if (WIFSIGNALED(*status))
		g_minishell.status_code = 128 + WTERMSIG(*status);
}

void	executor(char **tokens)
{
	int	i;
	int	pid;
	int	status;

	i = -1;
	status = -1;
	init_executor(tokens);
	if (g_minishell.heredoc.heredoc_exited == 1)
	{
		g_minishell.status_code = 130;
		g_minishell.heredoc.heredoc_exited = 0;
		return ;
	}
	if (g_minishell.number_of_cmds > 1)
		while (++i < g_minishell.number_of_cmds)
			pid = handle_exec(i, &g_minishell.commands[i]);
	else
		pid = run_single_cmd(g_minishell.commands[0]);
	if (pid != -1)
		loop_wait(pid, &status);
	g_minishell.on_fork = 0;
}
