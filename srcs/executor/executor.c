/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:38:16 by revieira          #+#    #+#             */
/*   Updated: 2023/04/12 16:17:42 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void	executor(char **tokens)
{
	if (validate_redirects(tokens) == 1)
	{
		g_minishell.status_code = 1;
		return ;
	}
	init_pipeline(tokens);
	init_redirects();
}
