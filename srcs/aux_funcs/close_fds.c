/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:15:12 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/19 17:55:03 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void	close_fds_in_child(void)
{
	int			i;
	int			size;
	t_command	cmd;

	i = 0;
	size = g_minishell.number_of_cmds;
	while (i < size)
	{
		cmd = g_minishell.commands[i];
		if (cmd.input_fd != 0)
			close(cmd.input_fd);
		if (cmd.output_fd != 1)
			close(cmd.output_fd);
		if (cmd.pipe[0] != 0)
			close(cmd.pipe[0]);
		if (cmd.pipe[1] != 0)
			close(cmd.pipe[1]);
		i++;
	}
}

void	close_fds(void)
{
	int	i;
	int	commands_size;

	i = 0;
	commands_size = g_minishell.number_of_cmds;
	if (g_minishell.commands == NULL)
		return ;
	while (i < commands_size)
	{
		if (g_minishell.commands[i].input_fd != 0)
			close(g_minishell.commands[i].input_fd);
		if (g_minishell.commands[i].output_fd != 1)
			close(g_minishell.commands[i].output_fd);
		i++;
	}
}
