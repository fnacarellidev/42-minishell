/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:38:16 by revieira          #+#    #+#             */
/*   Updated: 2023/04/17 15:23:42 by revieira         ###   ########.fr       */
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
}

void	executor(char **tokens)
{
	int	pid;

	if (validate_redirects(tokens) == 1)
	{
		g_minishell.status_code = 1;
		return ;
	}
	init_executor(tokens);
	pid = fork();
	if (pid == 0)
	{
		if (g_minishell.commands[0].input_fd != 0)
			dup2(g_minishell.commands[0].input_fd, 0);
		if (g_minishell.commands[0].output_fd != 1)
			dup2(g_minishell.commands[0].output_fd, 1);
		if (g_minishell.commands[0].bin_path != NULL)
			execve(g_minishell.commands[0].bin_path, g_minishell.commands[0].args, g_minishell.envp);
		ft_free_commands();
		ft_free_matrix((void **)tokens);
		ft_free_matrix((void **)g_minishell.envp);
		ft_free_list(&g_minishell.envp_list);
		rl_clear_history();
		exit(1);
	}
	wait(NULL);
}
