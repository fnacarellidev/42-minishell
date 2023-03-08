/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minicd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:16:11 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/08 15:30:09 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

static int	is_valid_dir(char *path)
{
	int	check;

	check = access(path, F_OK);
	if (check == 0)
		return (1);
	else
		return (0);
}

static int	is_valid_instruction(char *cmd)
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
	else if (!is_valid_dir(cmd_tokens[1]))
	{
		printf("bash: cd: %s: No such file or directory\n", cmd_tokens[1]);
		ret = 0;
	}
	ft_free_matrix((void **)cmd_tokens);
	return (ret);
}

static int	number_of_params(char *cmd)
{
	char	**tokens;
	int		amount_of_tokens;

	tokens = ft_split(cmd, ' ');
	amount_of_tokens = ft_count_matrix((void **)tokens);
	ft_free_matrix((void **)tokens);
	return (amount_of_tokens - 1);
}

void	cd_home(t_node **envp_list)
{
	char	new_pwd[16384];
	char	*oldpwd;

	if (!key_exists(*envp_list, "HOME="))
	{
		printf("bash: cd: HOME not set\n");
		return ;
	}
	if (!key_exists(*envp_list, "PWD="))
		ft_export(envp_list, "PWD=", "");
	if (!key_exists(*envp_list, "OLDPWD="))
		ft_export(envp_list, "OLDPWD=", "");
	oldpwd = get_key_value(*envp_list, "PWD=");
	change_value_from_key(envp_list, "OLDPWD=", oldpwd);
	chdir(get_key_value(*envp_list, "HOME="));
	getcwd(new_pwd, 16384);
	change_value_from_key(envp_list, "PWD=", new_pwd);
}

void	change_directory(t_node **envp_list, char *str)
{
	char	*oldpwd;
	char	buf[16384];

	if (number_of_params(str) == 0)
		cd_home(envp_list);
	else
	{
		if (!is_valid_instruction(str))
			return ;
		oldpwd = get_key_value(*envp_list, "PWD=");
		change_value_from_key(envp_list, "OLDPWD=", oldpwd);
		chdir(&str[3]);
		getcwd(buf, 16384);
		change_value_from_key(envp_list, "PWD=", buf);
	}
}
