/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:37:50 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/26 20:40:21 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	ft_pwd(t_command cmd)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cmd.args[0])
		printf("%s\n", cwd);
	ft_free(cwd);
	if (g_minishell.on_fork)
		die_child(0, 0);
	return (0);
}
