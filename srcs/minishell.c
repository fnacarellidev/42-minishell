/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:12:01 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/28 13:31:05 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"
#include "libft/libft.h"

t_minishell	g_minishell;

void	ft_print_stack(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		printf("Node %d: %s%s\n", i, stack->key, stack->value);
		stack = stack->next;
		i++;
	}
}

void	ft_print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}

void	init_minishell(void)
{
	g_minishell.status_code = 0;
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd;
	char	**tokens;
	t_node	*envp_list;

	if (argc && argv)
	{}
	envp_list = get_envp_list(envp);
	init_minishell();
	while (1)
	{
		cmd = readline("$ ");
		if (ft_strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			break ;
		}
		tokens = lexer(cmd);
		parser(tokens);
		free(cmd);
		ft_print_matrix(tokens);
		ft_free_matrix((void **)tokens);
	}
	ft_free_list(&envp_list);
	return (0);
}
