/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:15:12 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/11 17:16:04 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void	close_fds(void)
{
	if (g_minishell.pipeline.input_fd != 0)
		close(g_minishell.pipeline.input_fd);
	if (g_minishell.pipeline.output_fd != 1)
		close(g_minishell.pipeline.output_fd);
}
