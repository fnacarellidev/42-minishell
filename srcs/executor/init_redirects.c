/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:06:37 by revieira          #+#    #+#             */
/*   Updated: 2023/04/12 16:21:45 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	fill_fds(t_command *command)
{
	int		i;
	char	**args;

	i = 0;
	args = command->args;
	command->input_fd = 0;
	command->output_fd = 1;
	while (args[i])
	{
		if (ft_strcmp("<<", args[i]) == 0)
			swap_stream_fd("input", command, get_heredoc_fd(args[++i]));
		else if (ft_strcmp("<", args[i]) == 0)
			swap_stream_fd("input", command, open(args[++i], O_RDONLY));
		else if (ft_strcmp(">", args[i]) == 0)
			swap_stream_fd("output", command, open(args[++i], O_WRONLY));
		else if (ft_strcmp(">>", args[i]) == 0)
			swap_stream_fd("output", command, open(args[++i], \
				O_WRONLY | O_APPEND));
		i++;
	}
}

void	init_redirects(void)
{
	int	i;
	int	args;

	i = 0;
	args = g_minishell.number_of_cmds;
	while (i < args)
	{
		fill_fds(&g_minishell.commands[i]);
		i++;
	}
}
