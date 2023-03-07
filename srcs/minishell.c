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

t_node	*get_envp_list(char **envp)
{
	int		i;
	char	*tmp;
	char	**split_key_value;
	t_node	*envp_list;
	t_node	*new_node;

	i = 0;
	envp_list = NULL;
	while (envp[i] != NULL)
	{
		split_key_value = ft_split(envp[i], '=');
		tmp = ft_strjoin(split_key_value[0], "=");
		new_node = ft_lstnew(tmp, split_key_value[1]);
		free(tmp);
		ft_free_matrix((void **)split_key_value);
		ft_lstadd_back(&envp_list, new_node);
		i++;
	}
	return (envp_list);
}
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
