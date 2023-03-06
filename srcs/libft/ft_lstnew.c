/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:37:02 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/06 16:21:02 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_node	*ft_lstnew(char *content)
{
	t_node	*new_node;

	new_node = (malloc(sizeof(t_node)));
	if (!new_node)
		return (0);
	new_node->data = ft_strdup(content);
	new_node->next = NULL;
	return (new_node);
}
