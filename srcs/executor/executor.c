/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:38:16 by revieira          #+#    #+#             */
/*   Updated: 2023/04/20 13:21:32 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

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
