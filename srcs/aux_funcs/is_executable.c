/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_executable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:51:53 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/13 13:56:54 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	is_executable(char *cmd)
{
	int	access_ret;

	access_ret = access(cmd, F_OK);
	if (access_ret == -1)
		return (access_ret);
	access_ret = access(cmd, X_OK);
	if (access_ret == -1)
		return (access_ret);
	return (access_ret);
}
