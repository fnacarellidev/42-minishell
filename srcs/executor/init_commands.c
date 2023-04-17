/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:14:37 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/17 15:02:19 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	count_args(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] && ft_strcmp("|", tokens[i]) != 0)
		i++;
	return (i);
}

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

void	init_commands(char **tokens, int idx)
{
	int		i;
	int		args;

	i = 0;
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
