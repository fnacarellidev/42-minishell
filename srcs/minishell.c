/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:12:01 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/06 16:22:32 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"
#include "libft/libft.h"

t_node	*get_envp_list(char **envp)
{
	int		i;
	t_node	*new_node;
	t_node	*envp_list;

	i = 0;
	envp_list = NULL;
	while (envp[i] != NULL)
	{
		new_node = ft_lstnew(envp[i]);
		ft_lstadd_back(&envp_list, new_node);
		i++;
	}
	return (envp_list);
}

int main(int argc, char **argv, char **envp)
{
	int		i;
	t_node	*list;

	i = 0;
	if (argc || argv)
	{
		list = get_envp_list(envp);
		ft_print_stack(list);
		ft_free_list(&list);
	}
	return (0);
}
