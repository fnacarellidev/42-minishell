/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:21:26 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/28 10:39:04 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	ft_env(t_command cmd)
{
	int	out;

	out = 1;
	handle_output(cmd, &out);
	if (cmd.args[0])
		ft_print_matrix_fd(g_minishell.envp, out);
	if (g_minishell.on_fork)
		die_child(0, 0);
	return (0);
}
