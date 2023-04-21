/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_possible_redirect_error.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:18:06 by revieira          #+#    #+#             */
/*   Updated: 2023/04/21 16:59:13 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	err_on_input_redirect(char *filename)
{
	int	error;

	if (access(filename, F_OK) == -1)
		error = ENOENT;
	else
		error = EACCES;
	ft_printf(STDERR_FILENO, "bash: %s: %s\n", filename, strerror(error));
}

static void	err_on_output(char *filename)
{
	int	error;

	if (ft_strlen(filename) > 255)
		error = ENAMETOOLONG;
	else
		error = EACCES;
	ft_printf(STDERR_FILENO, "bash: %s: %s\n", filename, strerror(error));
}

static int	test_filename(char *filename, char *redirect)
{
	int	fd;

	if (ft_strcmp(redirect, ">") == 0)
		fd = open(filename, O_RDONLY);
	else if (ft_strcmp(redirect, ">>") == 0)
		fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
		close(fd);
	return (fd);
}

void	print_possible_redirect_error(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (ft_strcmp(tokens[i], "<") == 0 \
				&& test_filename(tokens[i + 1], "<") == -1)
			err_on_input_redirect(tokens[i + 1]);
		else if (ft_strcmp(tokens[i], ">") == 0 \
				&& test_filename(tokens[i + 1], ">") == -1)
			err_on_output(tokens[i + 1]);
		else if (ft_strcmp(tokens[i], ">>") == 0 \
				&& test_filename(tokens[i + 1], ">>") == -1)
			err_on_output(tokens[i + 1]);
		i++;
	}
}
