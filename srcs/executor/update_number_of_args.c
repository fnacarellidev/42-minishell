/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_number_of_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:10:21 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/25 20:10:37 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void	update_number_of_args(void)
{
	int			i;
	int			size;
	t_command	*cmd;

	i = 0;
	size = g_minishell.number_of_cmds;
	while (i < size)
	{
		cmd = &g_minishell.commands[i];
		cmd->number_of_args = count_args(cmd->args);
		i++;
	}
}
