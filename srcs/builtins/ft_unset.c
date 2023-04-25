/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:54:34 by revieira          #+#    #+#             */
/*   Updated: 2023/04/25 15:21:12 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	is_valid_identifier(char *var)
{
	int	i;

	i = 0;
	if (!ft_isalpha(var[i]) && var[i] != '_')
		return (0);
	i++;
	while (var[i] && var[i] != '=')
	{
		if (!is_bash_char(var[i]))
			return (0);
		i++;
	}
	return (1);
}

void	delet_specific_node(t_node **envp_list, char *key)
{
	t_node	*curr;
	t_node	*prev;

	curr = *envp_list;
	prev = *envp_list;
	if (ft_strcmp(curr->key, key) == 0)
	{
		*envp_list = (*envp_list)->next;
		ft_lstdelone(curr, &free);
		return ;
	}
	while (ft_strcmp(curr->key, key) != 0 && curr)
	{
		prev = curr;
		curr = curr->next;
	}
	if (!curr)
		return ;
	prev->next = curr->next;
	ft_lstdelone(curr, &free);
}

static int	exec_unset(char *delet_var)
{
	if (!is_valid_identifier(delet_var))
	{
		printf("bash: unset: `%s': not a valid identifier\n", delet_var);
		return (1);
	}
	if (key_exists(g_minishell.envp_list, delet_var))
	{
		delet_specific_node(&g_minishell.envp_list, delet_var);
		update_env();
	}
	return (0);
}

int	ft_unset(t_command cmd)
{
	int	i;
	int	status;

	i = 1;
	status = 0;
	if (cmd.number_of_args > 1)
	{
		while (cmd.args[i])
		{
			if (exec_unset(cmd.args[i]))
				status = 1;
			i++;
		}
	}
	return (status);
}
