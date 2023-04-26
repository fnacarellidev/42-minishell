/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:21:33 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/26 13:50:51 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void	swap_pwds(char *new_dir)
{
	char	*pwd;
	t_node	**envp;

	envp = &g_minishell.envp_list;
	pwd = getcwd(NULL, 0);
	if (key_exists(*envp, "OLDPWD"))
		change_value_from_key(envp, "OLDPWD", pwd);
	ft_free(pwd);
	chdir(new_dir);
	pwd = getcwd(NULL, 0);
	if (key_exists(*envp, "PWD"))
		change_value_from_key(envp, "PWD", pwd);
	ft_free(pwd);
}

int	change_home(void)
{
	char	*value;

	value = get_key_value(g_minishell.envp_list, "HOME");
	if (ft_strlen(value))
		swap_pwds(value);
	else
	{
		ft_printf(STDERR_FILENO, "bash: cd: HOME not set\n");
		return (1);
	}
	return (0);
}

int	type_of_file(char *file)
{
	struct stat	file_status;

	if (!file)
		return (NO_SUCH_FILE);
	file_status.st_mode = 0;
	stat(file, &file_status);
	if (S_ISREG(file_status.st_mode))
		return (REG_FILE);
	else if (S_ISDIR(file_status.st_mode))
		return (DIR_FILE);
	return (NO_SUCH_FILE);
}

static void	print_error(t_command cmd, int filetype)
{
	if (filetype == REG_FILE)
		ft_printf(STDERR_FILENO, \
		"bash: cd: %s: Not a directory\n", cmd.args[1]);
	else
		ft_printf(STDERR_FILENO, \
		"bash: cd: %s: No such file or directory\n", cmd.args[1]);
}

int	ft_cd(t_command cmd)
{
	int	status;
	int	filetype;

	status = 1;
	if (cmd.number_of_args == 1)
		status = change_home();
	else if (cmd.number_of_args > 2)
		ft_printf(STDERR_FILENO, "bash: cd: too many arguments\n");
	else
	{
		filetype = type_of_file(cmd.args[1]);
		if (filetype == REG_FILE || filetype == NO_SUCH_FILE)
			print_error(cmd, filetype);
		else
		{
			status = 0;
			swap_pwds(cmd.args[1]);
		}
	}
	update_env();
	if (g_minishell.on_fork)
		die_child(0, status);
	return (status);
}
