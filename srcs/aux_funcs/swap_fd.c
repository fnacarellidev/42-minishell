/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:52:43 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/11 17:05:18 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	swap_fd_input(int new_fd)
{
	if (g_minishell.pipeline.input_fd != 0)
		close(g_minishell.pipeline.input_fd);
	g_minishell.pipeline.input_fd = new_fd;
}

static void	swap_fd_output(int new_fd)
{
	if (g_minishell.pipeline.output_fd != 1)
		close(g_minishell.pipeline.output_fd);
	g_minishell.pipeline.output_fd = new_fd;
}

void	swap_stream_fd(char *stream, int new_fd)
{
	if (ft_strcmp(stream, "input") == 0)
		swap_fd_input(new_fd);
	else
		swap_fd_output(new_fd);
}
