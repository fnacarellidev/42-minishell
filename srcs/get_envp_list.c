/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:50:30 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/26 17:38:44 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

char	**get_matrix_with_key_value(char *env_variable)
{
	long int	adresses_diff;
	char		**key_and_value;
	char		*equal_occurence;

	equal_occurence = ft_strchr(env_variable, '=');
	adresses_diff = ft_labs(env_variable - equal_occurence);
	key_and_value = ft_calloc(sizeof(char *), 3);
	key_and_value[0] = ft_calloc(sizeof(char), adresses_diff + 1);
	ft_strlcpy(key_and_value[0], env_variable, adresses_diff + 1);
	if (equal_occurence)
		key_and_value[1] = ft_strdup(++equal_occurence);
	else
		key_and_value[1] = NULL;
	return (key_and_value);
}

t_node	*get_envp_list(char **envp)
{
	int		i;
	char	**key_and_value;
	t_node	*envp_list;
	t_node	*new_node;

	i = 0;
	envp_list = NULL;
	while (envp[i] != NULL)
	{
		key_and_value = get_matrix_with_key_value(envp[i]);
		new_node = ft_lstnew(key_and_value[0], key_and_value[1], envp[i]);
		ft_free_matrix((void **)key_and_value);
		ft_lstadd_back(&envp_list, new_node);
		i++;
	}
	return (envp_list);
}

static int	amount_of_valid_keys(t_node **envp)
{
	int		size;
	t_node *tmp;

	size = 0;
	tmp = *envp;
	while (tmp)
	{
		if (tmp->value && tmp->env_line)
			size++;
		tmp = tmp->next;
	}
	return (size);
}

char	**get_envp(void)
{
	int		i;
	int		size;
	char	**envp;
	t_node	*tmp;

	i = 0;
	tmp = g_minishell.envp_list;
	size = ft_lstsize(g_minishell.envp_list);
	envp = ft_calloc(sizeof(char *), size + 1);
	while (tmp)
	{
		if (tmp->value)
			envp[i] = ft_strdup(tmp->env_line);
		tmp = tmp->next;
		i++;
	}
	return (envp);
}
