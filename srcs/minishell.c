/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:12:01 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/28 11:40:00 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"
#include "libft/libft.h"

t_minishell	g_minishell;

void	init_minishell(char **envp)
{
	g_minishell.status_code = 0;
	g_minishell.on_fork = 0;
	g_minishell.envp_list = get_envp_list(envp);
	g_minishell.envp = get_envp();
	g_minishell.builtins[0] = ft_echo;
	g_minishell.builtins[1] = ft_cd;
	g_minishell.builtins[2] = ft_pwd;
	g_minishell.builtins[3] = ft_export;
	g_minishell.builtins[4] = ft_unset;
	g_minishell.builtins[5] = ft_env;
	g_minishell.builtins[6] = ft_exit;
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
		if (parser(&tokens) == 1 || *tokens == NULL)
		{
			ft_free_matrix((void **)tokens);
			return (NULL);
		}
	}
	return (tokens);
}

static void	print_possible_errors(void)
{
	int			i;
	int			size;
	t_command	cmd;

	i = 0;
	size = g_minishell.number_of_cmds;
	while (i < size && get_builtin_pos(g_minishell.commands[i].args[0]) == -1)
	{
		cmd = g_minishell.commands[i];
		print_curr_err(cmd);
		i++;
	}
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
			print_possible_errors();
			ft_free_commands();
		}
	}
	return (0);
}
