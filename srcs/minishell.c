/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:12:01 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/12 16:31:03 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

t_minishell	g_minishell;

void	ft_print_stack(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		printf("Node %d: %s%s\n", i, stack->key, stack->value);
		stack = stack->next;
		i++;
	}
}

void	ft_print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}

void	handler(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	init_minishell(void)
{
	g_minishell.status_code = 0;
	g_minishell.pipeline.input_fd = 0;
	g_minishell.pipeline.output_fd = 1;
}

void	die(void)
{
	rl_clear_history();
	ft_free_list(&g_minishell.envp);
	close_fds();
	unlink(TMPFILE);
	write(1, "exit\n", 5);
	exit(0);
}

void	ft_free_commands(void)
{
	int	i;
	int	args;

	i = 0;
	args = g_minishell.number_of_cmds;
	close_fds();
	while (i < args)
	{
		ft_free_matrix((void **)g_minishell.commands[i].args);
		i++;
	}
	free(g_minishell.commands);
	g_minishell.commands = NULL;
}

char	**pipeline_validation(char *cmd)
{
	char	**tokens;

	if (cmd == NULL)
		die();
	if (!(cmd[0] == '\0') && cmd)
		add_history(cmd);
	tokens = lexer(cmd);
	free(cmd);
	if (parser(tokens) == 1)
	{
		ft_free_matrix((void **)tokens);
		return (NULL);
	}
	return(tokens);
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd;
	char	**tokens;

	if (argc && argv)
	{}
	g_minishell.envp = get_envp_list(envp);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	init_minishell();
	while (1)
	{
		cmd = readline("$ ");
		tokens = pipeline_validation(cmd);
		if (tokens)
		{
			executor(tokens);
			ft_print_matrix(tokens);
			ft_free_commands();
			ft_free_matrix((void **)tokens);
		}
	}
	return (0);
}
