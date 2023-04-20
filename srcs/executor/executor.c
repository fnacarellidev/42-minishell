/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:38:16 by revieira          #+#    #+#             */
/*   Updated: 2023/04/20 13:00:50 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void	print_struct(void)
{
	int	i;
	int	args;

	i = 0;
	args = g_minishell.number_of_cmds;
	while (i < args)
	{
		ft_print_matrix(g_minishell.commands[i].args);
		i++;
	}
}

static int	count_commands(char **tokens)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tokens[i])
	{
		if (ft_strcmp("|", tokens[i]) == 0)
			j++;
		i++;
	}
	return (j + 1);
}

void	init_executor(char **tokens)
{
	int	number_of_cmds;

	g_minishell.number_of_cmds = count_commands(tokens);
	number_of_cmds = g_minishell.number_of_cmds;
	g_minishell.commands = ft_calloc(sizeof(t_command), number_of_cmds + 1);
	init_commands(tokens, 0);
	init_redirects();
	remove_redirects();
	remove_quotes();
	init_bin_path();
	ft_free_matrix((void **)tokens);
}

int	run_single_cmd(t_command cmd)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (cmd.error)
			die_child(cmd);
		dup2(cmd.input_fd, 0);
		dup2(cmd.output_fd, 1);
		close_fds_in_child();
		execve(cmd.bin_path, cmd.args, g_minishell.envp);
	}
	return (pid);
}

void	handle_dups(t_command *prev, t_command *curr, t_command *next)
{
	if (!prev)
		dup2(curr->input_fd, 0);
	else
	{
		if (curr->input_fd == 0)
			dup2(prev->pipe[0], 0);
		else
			dup2(curr->input_fd, 0);
	}
	if (!next)
		dup2(curr->output_fd, 1);
	else
	{
		if (curr->output_fd == 1)
			dup2(curr->pipe[1], 1);
		else
			dup2(curr->output_fd, 1);
	}
}

int	ft_exec(t_command *prev, t_command *curr, t_command *next)
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

void	loop_wait(int pid, int *status)
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

int	handle_exec(int idx, t_command *curr)
{
	int			pid;
	t_command	prev;
	t_command	next;

	pid = -1;
	if (idx == 0)
	{
		next = g_minishell.commands[idx + 1];
		ft_exec(NULL, curr, &next);
		close(g_minishell.commands[idx].pipe[WR_END]);
	}
	else if (idx == g_minishell.number_of_cmds - 1)
	{
		prev = g_minishell.commands[idx - 1];
		pid = ft_exec(&prev, curr, NULL);
		close(g_minishell.commands[idx - 1].pipe[READ_END]);
	}
	else
	{
		next = g_minishell.commands[idx + 1];
		prev = g_minishell.commands[idx - 1];
		ft_exec(&prev, curr, &next);
		close(prev.pipe[READ_END]);
		close(curr->pipe[WR_END]);
	}
	return (pid);
}

void	executor(char **tokens)
{
	int	i;
	int	pid;
	int	status;

	i = 0;
	status = -1;
	if (validate_redirects(tokens) == 1)
	{
		g_minishell.status_code = 1;
		return ;
	}
	init_executor(tokens);
	if (g_minishell.number_of_cmds > 1)
	{
		while (i < g_minishell.number_of_cmds)
		{
			pid = handle_exec(i, &g_minishell.commands[i]);
			i++;
		}
	}
	else
		pid = run_single_cmd(g_minishell.commands[0]);
	loop_wait(pid, &status);
}
