/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:15:12 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/12 15:06:02 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void	close_fds(void)
{
	int	i;
	int	commands_size;

	i = 0;
	commands_size = g_minishell.number_of_cmds;
	while (i < commands_size)
	{
		if (g_minishell.commands[i].input_fd != 0)
			close(g_minishell.commands[i].input_fd);
		if (g_minishell.commands[i].output_fd != 1)
			close(g_minishell.commands[i].output_fd);
		i++;
	}
}
