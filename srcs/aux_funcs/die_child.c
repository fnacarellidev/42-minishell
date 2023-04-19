/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_child.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:50:27 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/19 18:12:18 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void	die_child(t_command cmd)
{
	int	exit_code;

	exit_code = cmd.error;
	close_fds_in_child();
	ft_free_commands();
	ft_free_matrix((void **)g_minishell.envp);
	ft_free_list(&g_minishell.envp_list);
	rl_clear_history();
	exit(exit_code);
}
