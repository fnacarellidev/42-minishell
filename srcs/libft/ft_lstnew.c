/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:37:02 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/03 11:47:07 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_node	*ft_lstnew(char *key, char *value, char *var)
{
	t_node	*new_node;

	new_node = (malloc(sizeof(t_node)));
	if (!new_node)
		return (0);
	new_node->key = ft_strdup(key);
	new_node->value = ft_strdup(value);
	new_node->env_line = ft_strdup(var);
	new_node->next = NULL;
	return (new_node);
}
