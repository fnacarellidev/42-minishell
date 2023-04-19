/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:38:16 by revieira          #+#    #+#             */
/*   Updated: 2023/04/19 17:59:44 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

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
	ft_free_matrix((void **)tokens);
}

int	run_single_cmd(t_command cmd)
{
	int	pid;
	int	exit_code;

	pid = fork();
	if (pid == 0)
	{
		if (cmd.error)
		{
			exit_code = cmd.error;
			if (exit_code == 2)
				exit_code = 127;
			close_stuff();
			ft_free_commands();
			ft_free_matrix((void **)g_minishell.envp);
			ft_free_list(&g_minishell.envp_list);
			rl_clear_history();
			exit(exit_code);
		}
		dup2(cmd.input_fd, 0);
		dup2(cmd.output_fd, 1);
		close_stuff();
		execve(cmd.bin_path, cmd.args, g_minishell.envp);
	}
	return (pid);
}

int	ft_exec(t_command *prev, t_command *curr, t_command *next)
{
	int	pid;
	int	exit_code;

	if (next)
		pipe(curr->pipe);
	pid = fork();
	if (pid == 0)
	{
		if (!prev)
			dup2(curr->input_fd, 0);
		else
			dup2(prev->pipe[0], 0);
		if (!next)
			dup2(curr->output_fd, 1);
		else
			dup2(curr->pipe[1], 1);
		close_stuff();
		if (curr->error)
		{
			exit_code = curr->error;
			if (exit_code == 2)
				exit_code = 127;
			ft_free_commands();
			ft_free_matrix((void **)g_minishell.envp);
			ft_free_list(&g_minishell.envp_list);
			rl_clear_history();
			exit(exit_code);
		}
		execve(curr->bin_path, curr->args, g_minishell.envp);
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
			if (i == 0)
			{
				ft_exec(NULL, &g_minishell.commands[i], &g_minishell.commands[i + 1]);
				close(g_minishell.commands[i].pipe[WR_END]);
			}
			else if (i == g_minishell.number_of_cmds - 1)
			{
				pid = ft_exec(&g_minishell.commands[i - 1], &g_minishell.commands[i], NULL);
				close(g_minishell.commands[i - 1].pipe[READ_END]);
			}
			else
			{
				ft_exec(&g_minishell.commands[i - 1], &g_minishell.commands[i], &g_minishell.commands[i + 1]);
				close_mid_pipes(i);
			}
			i++;
		}
		i = 0;
		while (i < g_minishell.number_of_cmds - 1)
		{
			wait(NULL);
			i++;
		}
	}
	else
		pid = run_single_cmd(g_minishell.commands[0]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		printf("cmd returned %d\n", WEXITSTATUS(status));
}
