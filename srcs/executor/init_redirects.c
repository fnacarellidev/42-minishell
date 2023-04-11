/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:06:37 by revieira          #+#    #+#             */
/*   Updated: 2023/04/11 17:12:33 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void	init_redirects(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (ft_strcmp("<<", tokens[i]) == 0)
			swap_stream_fd("input", get_heredoc_fd(tokens[++i]));
		else if (ft_strcmp("<", tokens[i]) == 0)
			swap_stream_fd("input", open(tokens[++i], O_RDONLY));
		else if (ft_strcmp(">", tokens[i]) == 0)
			swap_stream_fd("output", open(tokens[++i], O_WRONLY));
		else if (ft_strcmp(">>", tokens[i]) == 0)
			swap_stream_fd("output", open(tokens[++i], O_WRONLY | O_APPEND));
		i++;
	}
}
