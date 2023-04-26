/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:21:26 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/26 13:51:34 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	ft_env(t_command cmd)
{
	if (cmd.args[0])
		ft_print_matrix(g_minishell.envp);
	if (g_minishell.on_fork)
		die_child(0, 0);
	return (0);
}
