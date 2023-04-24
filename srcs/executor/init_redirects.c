/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:06:37 by revieira          #+#    #+#             */
/*   Updated: 2023/04/24 13:09:25 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	err_on_input_redirect(char *filename)
{
	int	error;

	if (access(filename, F_OK) == -1)
		error = ENOENT;
	else
		error = EACCES;
	ft_printf(STDERR_FILENO, "bash: %s: %s\n", filename, strerror(error));
}

static void	err_on_output_redirect(char *filename)
{
	int	error;

	if (ft_strlen(filename) > 255)
		error = ENAMETOOLONG;
	else
		error = EACCES;
	ft_printf(STDERR_FILENO, "bash: %s: %s\n", filename, strerror(error));
}

static void	fill_fds(t_command *cmd)
{
	int		i;

	i = 0;
	cmd->input_fd = 0;
	cmd->output_fd = 1;
	while (cmd->args[i])
	{
		if (ft_strcmp("<<", cmd->args[i]) == 0)
			g_minishell.heredoc.heredoc_exited = heredoc(cmd, cmd->args[++i]);
		else if (ft_strcmp("<", cmd->args[i]) == 0)
			swap_stream_fd("input", cmd, open(cmd->args[++i], O_RDONLY));
		else if (ft_strcmp(">", cmd->args[i]) == 0)
			swap_stream_fd("output", cmd, open(cmd->args[++i], O_WRONLY));
		else if (ft_strcmp(">>", cmd->args[i]) == 0)
			swap_stream_fd("output", cmd, open(cmd->args[++i], \
				O_WRONLY | O_APPEND));
		if (g_minishell.heredoc.heredoc_exited != 0)
			return ;
		else if (cmd->input_fd == -1 || cmd->output_fd == -1)
			return ;
		i++;
	}
}

void	init_redirects(void)
{
	int	i;
	int	args;

	i = 0;
	args = g_minishell.number_of_cmds;
	while (i < args && !g_minishell.heredoc.heredoc_exited)
	{
		fill_fds(&g_minishell.commands[i]);
		i++;
	}
}
