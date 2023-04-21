/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_filename.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:15:31 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/21 17:36:34 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	test_filename(char *filename, char *redirect)
{
	int	fd;

	if (ft_strcmp(redirect, ">") == 0)
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (ft_strcmp(redirect, ">>") == 0)
		fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		fd = open(filename, O_RDONLY);
	if (fd != -1)
		close(fd);
	return (fd);
}
