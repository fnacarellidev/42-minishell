/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:06:37 by revieira          #+#    #+#             */
/*   Updated: 2023/04/10 18:24:01 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static char	*get_filename_of_given_token(char **tokens, char redirect)
{
	int	last_pos;

	last_pos = ft_count_matrix((void **)tokens) - 1;
	while (last_pos >= 0)
	{
		if (tokens[last_pos][0] == redirect)
			return (tokens[last_pos + 1]);
		last_pos--;
	}
	return (NULL);
}

void	init_redirects(char **tokens)
{
	char	*input_filename;
	char	*output_filename;

	input_filename = get_filename_of_given_token(tokens, '<');
	output_filename = get_filename_of_given_token(tokens, '>');
	if (input_filename)
		g_minishell.pipeline.input_fd = open(input_filename, O_RDONLY);
	if (output_filename)
		g_minishell.pipeline.output_fd = open(output_filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
}
