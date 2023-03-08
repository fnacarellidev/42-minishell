/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:53:17 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/08 15:03:32 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	ft_export(t_node **envp_list, char *key, char *value)
{
	t_node	*new_node;

	new_node = ft_lstnew(key, value);
	ft_lstadd_back(envp_list, new_node);
}
