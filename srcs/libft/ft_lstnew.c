/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:37:02 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/25 17:20:33 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_node	*ft_lstnew(char *key, char *value, char *var)
{
	t_node	*new_node;

	new_node = (malloc(sizeof(t_node)));
	if (!new_node)
		return (0);
	if (key)
		new_node->key = ft_strdup(key);
	else
		new_node->key = NULL;
	if (value)
		new_node->value = ft_strdup(value);
	else
		new_node->value = NULL;
	if (var)
		new_node->env_line = ft_strdup(var);
	else
		new_node->env_line = NULL;
	new_node->next = NULL;
	return (new_node);
}
