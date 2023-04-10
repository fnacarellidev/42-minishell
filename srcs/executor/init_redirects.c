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
