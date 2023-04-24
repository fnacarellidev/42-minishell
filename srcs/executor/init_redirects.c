/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:06:37 by revieira          #+#    #+#             */
/*   Updated: 2023/04/24 13:36:49 by revieira         ###   ########.fr       */
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

int	is_output_redirect(char *redirect)
{
	if (ft_strcmp(redirect, ">") == 0 || ft_strcmp(redirect, ">>") == 0)
		return (1);
	return (0);
}

int	is_input_redirect(char *redirect)
{
	if (ft_strcmp(redirect, "<") == 0 || ft_strcmp(redirect, "<<") == 0)
		return (1);
	return (0);
}

void	set_output_fd(t_command *cmd, char *redirect, char *filename)
{
	int	flags;

	if (ft_strcmp(">", redirect) == 0)
	{
		flags = O_CREAT | O_WRONLY | O_TRUNC;
		swap_stream_fd("output", cmd, open(filename, flags, 0644));
	}
	else
	{
		flags = O_CREAT | O_WRONLY | O_APPEND;
		swap_stream_fd("output", cmd, open(filename, flags, 0644));
	}
}

void	set_input_fd(t_command *cmd, char *redirect, char *filename)
{
	char	*delim;

	if (ft_strcmp("<", redirect) == 0)
		swap_stream_fd("input", cmd, open(filename, O_RDONLY));
	else
	{
		delim = filename;
		g_minishell.heredoc.heredoc_exited = heredoc(cmd, delim);
	}
}

int	has_error(t_command *cmd)
{
	if (g_minishell.heredoc.heredoc_exited != 0 \
		|| cmd->input_fd == -1 || cmd->output_fd == -1)
		return (1);
	return (0);
}

void	handle_error(t_command *cmd, char *filename)
{
	if (cmd->input_fd == -1)
		err_on_input_redirect(filename);
	else if (cmd->output_fd == -1)
		err_on_output_redirect(filename);
}

static void	fill_fds(t_command *cmd)
{
	int	i;

	i = 0;
	cmd->input_fd = 0;
	cmd->output_fd = 1;
	while (cmd->args[i])
	{
		if (is_input_redirect(cmd->args[i]))
			set_input_fd(cmd, cmd->args[i], cmd->args[i + 1]);
		else if (is_output_redirect(cmd->args[i]))
			set_output_fd(cmd, cmd->args[i], cmd->args[i + 1]);
		if (has_error(cmd))
		{
			handle_error(cmd, cmd->args[i + 1]);
			return ;
		}
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
