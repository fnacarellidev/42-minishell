/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_redirects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:18:06 by revieira          #+#    #+#             */
/*   Updated: 2023/04/21 16:07:10 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	validate_input_redirects(char *filename)
{
	int	fd;
	int	error;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		if (access(filename, F_OK) == -1)
			error = ENOENT;
		else
			error = EACCES;
		ft_printf(2, "bash: %s: %s\n", filename, strerror(error));
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
		ft_printf(2, "bash: %s: %s\n", filename, strerror(error));
		return (1);
	}
	close(fd);
	return (0);
}

static int	validate_append_redirects(char *filename)
{
	int	fd;
	int	error;

	fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		if (ft_strlen(filename) > 255)
			error = ENAMETOOLONG;
		else
			error = EACCES;
		ft_printf(2, "bash: %s: %s\n", filename, strerror(error));
		return (1);
	}
	close(fd);
	return (0);
}

int	validate_redirects(char **tokens)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (tokens[i] && ret == 0)
	{
		if (ft_strcmp(tokens[i], "<") == 0)
			ret = validate_input_redirects(tokens[i + 1]);
		else if (ft_strcmp(tokens[i], ">") == 0)
			ret = validate_output_redirects(tokens[i + 1]);
		else if (ft_strcmp(tokens[i], ">>") == 0)
			ret = validate_append_redirects(tokens[i + 1]);
		i++;
	}
	return (ret);
}
