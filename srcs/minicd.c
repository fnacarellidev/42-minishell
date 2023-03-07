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

static char	*get_key_value(t_node *envp_list, char *key)
{
	while (ft_strcmp(envp_list->key, key) != 0)
		envp_list = envp_list->next;
	return (envp_list->value);
}

static void	change_value_from_key(t_node **envp_list, char *key, char *new_data)
{
	t_node	*tmp;

	tmp = *envp_list;
	while (ft_strcmp(tmp->key, key) != 0)
		tmp = tmp->next;
	if (tmp->value)
		free(tmp->value);
	tmp->value = ft_strdup(new_data);
}

static int	is_valid_instruction(t_node **envp_list, char *cmd)
{
	int		ret;
	char	**cmd_tokens;
	int		number_of_tokens;

	ret = 1;
	cmd_tokens = ft_split(cmd, ' ');
	number_of_tokens = ft_count_matrix((void **)cmd_tokens);
	if (number_of_tokens > 2)
	{
		printf("bash: cd: too many arguments");
		ret = 0;
	}
	else if (!key_exists(*envp_list, "PWD="))
		export(envp_list, "PWD=", NULL);
	else if (!key_exists(*envp_list, "OLDPWD="))
		export(envp_list, "OLDPWD=", NULL);
	else if (!is_valid_dir(cmd_tokens[1]))
	{
		printf("bash: cd: %s: No such file or directory\n", cmd_tokens[1]);
		ret = 0;
	}
	ft_free_matrix((void **)cmd_tokens);
	return (ret);
}
