/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:36:32 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/12 19:16:47 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	exclude_redirects(char **tokens)
{
	int	i;
	int	mem_to_alloc;

	i = 0;
	mem_to_alloc = 0;
	while (tokens[i])
	{
		if (is_redirect(tokens[i]))
			i++;
		else
			mem_to_alloc++;
		i++;
	}
	return (mem_to_alloc);
}

static void	copy_tokens(char **new, char **copy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (copy[i])
	{
		if (is_redirect(copy[i]))
			i++;
		else
			new[j++] = ft_strdup(copy[i]);
		i++;
	}
}

static void	remove_redirect(char ***command_args)
{
	int		tokens_amount;
	char	**new_tokens;

	tokens_amount = exclude_redirects(*command_args);
	new_tokens = ft_calloc(sizeof(char *), tokens_amount + 1);
	copy_tokens(new_tokens, *command_args);
	ft_free_matrix((void **)*command_args);
	*command_args = new_tokens;
}

void	remove_redirects(void)
{
	int	i;
	int	args;

	i = 0;
	args = g_minishell.number_of_cmds;
	while (i < args)
	{
		remove_redirect(&g_minishell.commands[i].args);
		i++;
	}
}
