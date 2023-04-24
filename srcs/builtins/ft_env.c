/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:21:26 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/24 19:22:46 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	ft_env(t_command cmd)
{
	if (cmd.args[0])
		ft_print_matrix(g_minishell.envp);
	if (g_minishell.on_fork)
		exit(0);
	return (0);
}
