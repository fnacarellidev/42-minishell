/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:14:37 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/25 19:49:16 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	fill_args(char **tokens, int idx)
{
	int	i;
	int	args;

	i = 0;
	args = g_minishell.commands[idx].number_of_args;
	while (i < args)
	{
		g_minishell.commands[idx].args[i] = ft_strdup(tokens[i]);
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

void	init_commands(char **tokens, int idx)
{
	int		i;
	int		args;
	int		number_of_cmds;

	i = 0;
	if (idx == 0)
	{
		g_minishell.number_of_cmds = count_commands(tokens);
		number_of_cmds = g_minishell.number_of_cmds;
		g_minishell.commands = ft_calloc(sizeof(t_command), number_of_cmds + 1);
	}
	if (tokens[i] == NULL)
		return ;
	while (tokens[i] && ft_strcmp("|", tokens[i]) != 0)
		i++;
	if (tokens[i] && ft_strcmp("|", tokens[i]) == 0)
		i++;
	init_commands(tokens + i, idx + 1);
	args = count_args(tokens);
	g_minishell.commands[idx].number_of_args = args;
	g_minishell.commands[idx].args = ft_calloc(sizeof(char *), args + 1);
	fill_args(tokens, idx);
}
