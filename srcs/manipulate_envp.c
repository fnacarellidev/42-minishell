/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_envp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:16:32 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/26 16:24:48 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

char	*get_key_value(t_node *envp_list, char *key)
{
	if (key[0] == '?')
		return (ft_itoa(g_minishell.status_code));
	if (!key_exists(envp_list, key))
		return ("");
	while (ft_strcmp(envp_list->key, key) != 0)
		envp_list = envp_list->next;
	return (envp_list->value);
}

void	change_value_from_key(t_node **envp_list, char *key, char *new_data)
{
	t_node	*tmp;

	tmp = *envp_list;
	while (ft_strcmp(tmp->key, key) != 0)
		tmp = tmp->next;
	if (tmp->value)
		free(tmp->value);
	if (tmp->env_line)
		free(tmp->env_line);
	tmp->value = ft_strdup(new_data);
	tmp->env_line = ft_strjoin(tmp->key, "=");
	append(&tmp->env_line, ft_strdup(tmp->value));
}

int	key_exists(t_node *envp_list, char *key)
{
	char	*curr_key;
	int		comparison;

	while (envp_list != NULL)
	{
		curr_key = envp_list->key;
		comparison = ft_strcmp(curr_key, key);
		if (comparison == 0)
			return (1);
		envp_list = envp_list->next;
	}
	return (0);
}
