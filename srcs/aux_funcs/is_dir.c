/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:21:15 by revieira          #+#    #+#             */
/*   Updated: 2023/04/19 17:04:58 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	is_dir(const char *path)
{
	struct stat file_stat;

	file_stat.st_mode = 0;
	stat(path, &file_stat);
	return (S_ISDIR(file_stat.st_mode));
}
