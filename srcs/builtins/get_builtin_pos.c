/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:27:02 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/26 11:02:02 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	get_builtin_pos(char *str)
{
	if (!str)
		return (-1);
	if (ft_strcmp(str, "echo") == 0)
		return (0);
	else if (ft_strcmp(str, "cd") == 0)
		return (1);
	else if (ft_strcmp(str, "pwd") == 0)
		return (2);
	else if (ft_strcmp(str, "export") == 0)
		return (3);
	else if (ft_strcmp(str, "unset") == 0)
		return (4);
	else if (ft_strcmp(str, "env") == 0)
		return (5);
	else if (ft_strcmp(str, "exit") == 0)
		return (6);
	return (-1);
}
