/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:57:20 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/10 19:49:05 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	is_meta_char(char c)
{
	int		i;
	char	metachars[3] = {'>', '<', '|'};

	i = 0;
	while (i < 3)
	{
		if (c == metachars[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_metachars(char *cmd)
{
	int		amount_of_metachars;

	amount_of_metachars = 0;
	while (*cmd)
	{
		if (is_meta_char(*cmd))
			amount_of_metachars++;
		cmd++;
	}
	return (amount_of_metachars);
}
