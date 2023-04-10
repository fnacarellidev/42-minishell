/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:12:01 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/06 20:28:45 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"
#include "libft/libft.h"

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
}

void	die(void)
{
	rl_clear_history();
	ft_free_list(&g_minishell.envp);
	write(1, "exit\n", 5);
	exit(0);
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
		if (cmd == NULL)
			die();
		if (!(cmd[0] == '\0') && cmd)
			add_history(cmd);
		if (ft_strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			die();
		}
		tokens = lexer(cmd);
		parser(tokens);
		free(cmd);
		ft_print_matrix(tokens);
		ft_free_matrix((void **)tokens);
	}
	return (0);
}
