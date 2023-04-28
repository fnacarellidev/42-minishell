/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:56:21 by revieira          #+#    #+#             */
/*   Updated: 2023/04/28 11:16:13 by fnacarel         ###   ########.fr       */
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

static void	print_export(t_command cmd)
{
	char	*key;
	char	*value;
	t_node	*tmp;
	int		out;

	out = 1;
	handle_output(cmd, &out);
	tmp = g_minishell.envp_list;
	while (tmp)
	{
		key = tmp->key;
		value = tmp->value;
		if (key && value)
			ft_printf(out, "declare -x %s=\"%s\"\n", key, value);
		else
			ft_printf(out, "declare -x %s\n", key);
		tmp = tmp->next;
	}
}

static void	exec_export(char *new_var)
{
	char	**key_and_value;
	char	*key;
	char	*value;
	t_node	*new_node;

	if (!ft_strchr(new_var, '=') && key_exists(g_minishell.envp_list, new_var))
		return ;
	if (!ft_strchr(new_var, '=') && !key_exists(g_minishell.envp_list, new_var))
	{
		new_node = ft_lstnew(new_var, NULL, NULL);
		ft_lstadd_back(&g_minishell.envp_list, new_node);
		return ;
	}
	key_and_value = get_matrix_with_key_value(new_var);
	key = key_and_value[0];
	value = key_and_value[1];
	if (!key_exists(g_minishell.envp_list, key))
	{
		new_node = ft_lstnew(key, value, new_var);
		ft_lstadd_back(&g_minishell.envp_list, new_node);
	}
	else
		change_value_from_key(&g_minishell.envp_list, key, value);
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
		print_export(cmd);
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
	if (g_minishell.on_fork)
		die_child(0, status);
	return (status);
}
