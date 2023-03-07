/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:12:01 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/07 15:45:53 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"
#include "libft/libft.h"

{
int main(int argc, char **argv, char **envp)
{
	t_node	*envp_list;
	char	*line;

	if (argc && argv)
	{}
	envp_list = get_envp_list(envp);
	ft_print_stack(envp_list);
	ft_free_list(&envp_list);
	exit(0);
	while (1)
	{
		line = readline("$ ");
		if (ft_strlen(line) != 0)
			add_history(line);
		if (ft_strlen(line) > 0 && ft_strncmp(line, "exit\n", ft_strlen(line)) == 0)
		{
			free(line);
			exit(0);
		}
		free(line);
	}
	ft_free_list(&envp_list);
	return (0);
}
