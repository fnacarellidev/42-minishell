/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_redirects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:18:06 by revieira          #+#    #+#             */
/*   Updated: 2023/04/10 16:37:15 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	validate_input_redirects(char *filename)
{
	int	fd;
	int	error;

	fd = open(filename, O_RDONLY);
	printf("%d", fd);
	if (fd == -1)
	{
		if (access(filename, F_OK) == -1)
			error = ENOENT;
		else
			error = EACCES;
		printf("bash: %s: %s\n", filename, strerror(error));
		return (1);
	}
	close(fd);
	return (0);
}

static int	validate_output_redirects(char *filename)
{
	int	fd;
	int	error;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		if (ft_strlen(filename) > 255)
			error = ENAMETOOLONG;
		else
			error = EACCES;
		printf("bash: %s: %s\n", filename, strerror(error));
		return (1);
	}
	close(fd);
	return (0);
}
