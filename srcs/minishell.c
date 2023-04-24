/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:12:01 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/24 16:39:07 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

t_minishell	g_minishell;

void	init_minishell(char **envp)
{
	g_minishell.status_code = 0;
	g_minishell.on_fork = 0;
	g_minishell.envp_list = get_envp_list(envp);
	g_minishell.envp = get_envp();
	g_minishell.builtins[2] = ft_pwd;
}

void	die(void)
{
	rl_clear_history();
	ft_free_list(&g_minishell.envp_list);
	ft_free_matrix((void **)g_minishell.envp);
	close_fds();
	unlink(TMPFILE);
	write(1, "exit\n", 5);
	exit(0);
}

char	**pipeline_validation(char *cmd)
{
	char	**tokens;

	tokens = NULL;
	if (cmd == NULL)
		die();
	if (cmd[0] == '\0')
		ft_free(cmd);
	else
	{
		add_history(cmd);
		tokens = lexer(cmd);
		ft_free(cmd);
		if (parser(tokens) == 1)
		{
			ft_free_matrix((void **)tokens);
			return (NULL);
		}
	}
	return (tokens);
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd;
	char	**tokens;

	if (argc != 1 && !argv)
		return (0);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	init_minishell(envp);
	while (1)
	{
		cmd = readline("$ ");
		tokens = pipeline_validation(cmd);
		if (tokens)
		{
			executor(tokens);
			ft_free_commands();
		}
	}
	return (0);
}
