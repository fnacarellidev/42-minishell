/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:57:20 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/04 16:51:03 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	fix_tokens(char **tokens, char set[6])
{
	int	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		replace_between(tokens[i], set, SET1);
		i++;
	}
}

static void	init_set(char set[6])
{
	set[0] = 1;
	set[1] = 2;
	set[2] = 3;
	set[3] = 4;
	set[4] = 5;
	set[5] = 6;
}

char	**lexer(char *cmd)
{
	char	*str;
	char	**tokens;
	char	set[6];

	init_set(set);
	str = human_readable_cmd(cmd);
	replace_between(str, SET1, set);
	tokens = ft_split(str);
	fix_tokens(tokens, set);
	free(str);
	return (tokens);
}
