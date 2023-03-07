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
