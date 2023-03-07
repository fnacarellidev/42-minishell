/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:40:40 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/07 18:02:22 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

static int	get_key_position(t_node *envp_list, char *key)
{
	int	i;

	i = 0;
	while (ft_strcmp(envp_list->key, key) != 0 && envp_list != NULL)
	{
		envp_list = envp_list->next;
		i++;
	}
	if (envp_list == NULL)
		return (-1);
	return (i);
}

static t_node	*get_prev_node_with_position(t_node *node, int position)
{
	int	i;

	i = 0;
	while (i < position - 1)
	{
		node = node->next;
		i++;
	}
	return (node);
}

void	unset(t_node **envp_list, char *key)
{
	int		key_pos;
	t_node	*tmp;
	t_node	*node_to_del;

	key_pos = get_key_position(*envp_list, key);
	if (key_pos == -1)
		return ;
	if (key_pos == 0)
	{
		node_to_del = *envp_list;
		(*envp_list)->next = (*envp_list)->next;
	}
	else
	{
		tmp = get_prev_node_with_position(*envp_list, key_pos);
		node_to_del = tmp->next;
		tmp->next = tmp->next->next;
	}
	ft_lstdelone(node_to_del, free);
}
