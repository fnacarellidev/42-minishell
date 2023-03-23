/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:57:20 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/23 15:50:34 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	fix_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		replace_between(tokens[i], DEL_ASCII, SINGLE_QUOTE, ' ');
		replace_between(tokens[i], DEL_ASCII, DOUBLE_QUOTE, ' ');
		i++;
	}
}

char	**lexer(char *cmd)
{
	char	*str;
	char	**tokens;

	str = human_readable_cmd(cmd);
	erase_empty_quotes(str);
	replace_between(str, ' ', SINGLE_QUOTE, DEL_ASCII);
	replace_between(str, ' ', DOUBLE_QUOTE, DEL_ASCII);
	tokens = ft_split(str, ' ');
	fix_tokens(tokens);
	free(str);
	ft_free_matrix((void**)tokens);
	return (NULL);
}
