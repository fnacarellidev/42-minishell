/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_possible_redirect_error.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:18:06 by revieira          #+#    #+#             */
/*   Updated: 2023/04/21 17:15:49 by fnacarel         ###   ########.fr       */
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
