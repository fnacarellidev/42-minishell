/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:57:20 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/03 16:41:26 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	fix_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		replace_between(tokens[i], DEL_ASCII, ' ');
		i++;
	}
}

char	**lexer(char *cmd)
{
	char	*str;
	char	**tokens;

	str = human_readable_cmd(cmd);
	replace_between(str, ' ', DEL_ASCII);
	tokens = ft_split(str);
	fix_tokens(tokens);
	free(str);
	return (tokens);
}
