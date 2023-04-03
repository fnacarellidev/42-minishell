/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:50:30 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/29 22:14:30 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

static char	**get_matrix_with_key_value(char *env_variable)
{
	long int	adresses_diff;
	char		**key_and_value;
	char		*equal_occurence;

	equal_occurence = ft_strchr(env_variable, '=');
	adresses_diff = ft_labs(env_variable - equal_occurence);
	key_and_value = ft_calloc(sizeof(char *), 3);
	key_and_value[0] = ft_calloc(sizeof(char), adresses_diff + 1);
	ft_strlcpy(key_and_value[0], env_variable, adresses_diff + 1);
	key_and_value[1] = ft_strdup(++equal_occurence);
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
