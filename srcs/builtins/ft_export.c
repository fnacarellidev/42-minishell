/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:56:21 by revieira          #+#    #+#             */
/*   Updated: 2023/04/25 18:36:18 by revieira         ###   ########.fr       */
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

void	exec_export(char *new_var)
{
	char	**key_and_value;
	t_node	*new_node;

	if (!ft_strchr(new_var, '=') && key_exists(g_minishell.envp_list, new_var))
		return ;
	else if (!ft_strchr(new_var, '=') && !key_exists(g_minishell.envp_list, new_var))
	{
		new_node = ft_lstnew(new_var, NULL, NULL);
		ft_lstadd_back(&g_minishell.envp_list, new_node);
		return ;
	}
	key_and_value = get_matrix_with_key_value(new_var);
	if (!key_exists(g_minishell.envp_list, key_and_value[0]))
	{
		new_node = ft_lstnew(key_and_value[0], key_and_value[1], new_var);
		ft_lstadd_back(&g_minishell.envp_list, new_node);
	}
	else
		change_value_from_key(&g_minishell.envp_list, key_and_value[0], key_and_value[1]);
	ft_free_matrix((void **)key_and_value);
	update_env();
}

int	ft_export(t_command cmd)
{
	int	i;
	int	status;

	i = 1;
	status = 0;
	if (cmd.number_of_args == 1)
	{
		print_export();
		return (status);
	}
	while (cmd.args[i])
	{
		if (!is_valid_identifier(cmd.args[i]))
		{
			ft_printf(STDERR_FILENO, \
				"bash: export: `%s': not a valid identifier\n", cmd.args[i]);
			status = 1;
		}
		else
			exec_export(cmd.args[i]);
		i++;
	}
	return (status);
}
