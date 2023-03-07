/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minicd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:16:11 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/07 18:04:20 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

static int	is_valid_dir(char *str)
{
	int	check;

	check = access(str, F_OK);
	if (check == 0)
		return (1);
	else
		return (0);
}

static int	key_exists(t_node *envp_list, char *key)
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
