/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bin_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:42:12 by revieira          #+#    #+#             */
/*   Updated: 2023/04/20 12:50:14 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static char	**get_path_dirs(void)
{
	int		i;
	char	*path;
	char	**path_dirs;

	i = 0;
	path = get_key_value(g_minishell.envp_list, "PATH");
	path_dirs = ft_split_old(path, ':');
	while (path_dirs[i])
	{
		append(&path_dirs[i], ft_strdup("/"));
		i++;
	}
	return (path_dirs);
}

static char	*get_bin_path(t_command *command)
{
	int		i;
	char	*bin;
	char	**path_dirs;

	i = 0;
	path_dirs = get_path_dirs();
	while (path_dirs[i] && command->args[0] && ft_strlen(command->args[0]) > 0)
	{
		bin = ft_strjoin(path_dirs[i], command->args[0]);
		if (access(bin, F_OK | X_OK) == 0)
		{
			ft_free_matrix((void **)path_dirs);
			return (bin);
		}
		else if (access(bin, F_OK) == 0 && access(bin, X_OK) == -1)
		{
			command->error = EACCES;
			ft_free(bin);
			break ;
		}
		ft_free(bin);
		i++;
	}
	ft_free_matrix((void **)path_dirs);
	return (NULL);
}

static void	set_bin(t_command *cmd)
{
	cmd->error = 0;
	if (cmd->args[0] && access(cmd->args[0], F_OK | X_OK) == 0)
		cmd->bin_path = ft_strdup(cmd->args[0]);
	else
		cmd->bin_path = get_bin_path(cmd);
	if (cmd->bin_path && cmd->args[0] == NULL)
		cmd->error = 1;
	else if (is_dir(cmd->args[0]) && access(cmd->args[0], F_OK | X_OK) == 0)
		cmd->error = EISDIR;
	else if (ft_strchr(cmd->args[0], 47) && cmd->bin_path == NULL)
		cmd->error = ENOENT;
	else if (cmd->error == 0 && cmd->bin_path == NULL)
		cmd->error = ENOCMD;
}

void	init_bin_path(void)
{
	int	i;
	int	args;

	i = 0;
	args = g_minishell.number_of_cmds;
	while (i < args)
	{
		set_bin(&g_minishell.commands[i]);
		i++;
	}
}
