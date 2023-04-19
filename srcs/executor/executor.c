/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:38:16 by revieira          #+#    #+#             */
/*   Updated: 2023/04/19 13:55:03 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void	close_stuff(void)
{
	int			i;
	int			size;
	t_command	cmd;

	i = 0;
	size = g_minishell.number_of_cmds;
	while (i < size)
	{
		cmd = g_minishell.commands[i];
		if (cmd.input_fd != 0)
			close(cmd.input_fd);
		if (cmd.output_fd != 1)
			close(cmd.output_fd);
		if (cmd.pipe[0] != 0)
			close(cmd.pipe[0]);
		if (cmd.pipe[1] != 0)
			close(cmd.pipe[1]);
		i++;
	}
}

void	close_mid_pipes(int idx)
{
	t_command	prev_cmd;
	t_command	curr_cmd;

	prev_cmd = g_minishell.commands[idx - 1];
	curr_cmd = g_minishell.commands[idx];
	close(prev_cmd.pipe[READ_END]);
	close(curr_cmd.pipe[WR_END]);
}

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
}

void	ft_exec(t_command *prev, t_command *curr, t_command *next)
{
	int	pid;

	if (next->args != NULL)
		pipe(curr->fd);
	pid = fork();
	if (pid == 0)
	{
		if (!prev)
			dup2(curr->input_fd, 0);
		else
			dup2(prev->fd[0], 0);
		if (!next->args)
			dup2(curr->output_fd, 1);
		else
			dup2(curr->fd[1], 1);
		execve(curr->bin_path, curr->args, g_minishell.envp);
		perror("");
		exit(1);
	}
}

void	executor(char **tokens)
{
	int	i;

	if (validate_redirects(tokens) == 1)
	{
		g_minishell.status_code = 1;
		return ;
	}
	init_executor(tokens);
	i = 0;
	while (i < g_minishell.number_of_cmds)
	{
		if (i == 0)
			ft_exec(NULL, &g_minishell.commands[i], &g_minishell.commands[i + 1]);
		else
			ft_exec(&g_minishell.commands[i - 1], &g_minishell.commands[i], &g_minishell.commands[i + 1]);
		i++;
	}
	i = 0;
	while (i < g_minishell.number_of_cmds - 1)
	{
		wait(NULL);
		close(g_minishell.commands[i].fd[0]);
		close(g_minishell.commands[i].fd[1]);
		i++;
	}
}
