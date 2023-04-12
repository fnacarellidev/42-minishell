/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:12:01 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/12 17:03:24 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

t_minishell	g_minishell;

void	init_minishell(char **envp)
{
	g_minishell.status_code = 0;
	g_minishell.envp = get_envp_list(envp);
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
			ft_print_matrix(tokens);
			ft_free_commands();
			ft_free_matrix((void **)tokens);
		}
	}
	return (0);
}
