/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:12:01 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/22 16:51:20 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "../includes/minishell.h"
#include "libft/libft.h"

void    ft_print_stack(t_node *stack)
{
    int    i;

    i = 0;
    while (stack)
    {
		printf("Node %d: %s%s\n", i, stack->key, stack->value);
        stack = stack->next;
		i++;
    }
}

int main(int argc, char **argv, char **envp)
{
	t_node	*envp_list;

	if (argc && argv)
	{}
	envp_list = get_envp_list(envp);
	lexer(argv[1]);
	ft_free_list(&envp_list);
	return (0);
}
