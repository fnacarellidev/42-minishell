/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:37:50 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/28 12:35:50 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	ft_pwd(t_command cmd)
{
	char	*cwd;
	int		out;

	out = 1;
	handle_output(cmd, &out);
	cwd = getcwd(NULL, 0);
	if (cmd.args[0])
		ft_printf(out, "%s\n", cwd);
	ft_free(cwd);
	if (g_minishell.on_fork)
		die_child(0, 0);
	return (0);
}
