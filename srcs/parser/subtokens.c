/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtokens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:24:12 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/04 18:48:17 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

char	**get_subtokens(char *token, int idx)
{
	int		i;
	char	**subtokens;
	char	quoted;

	i = 0;
	if (*token == '\0')
		return (ft_calloc(idx + 1, sizeof(char *)));
	quoted = 0;
	if (is_quote(token[i]))
		quoted = token[i++];
	while (token[i] && ((quoted && quoted != token[i]) || !is_quote(token[i])))
		i++;
	if (quoted && is_quote(token[i]))
		i++;
	subtokens = get_subtokens(token + i, idx + 1);
	subtokens[idx] = ft_substr(token, 0, i);
	return (subtokens);
}

char	**subtokens(char *token)
{
	char	**subtokens;

	subtokens = get_subtokens(token, 0);
	ft_free_matrix((void **)subtokens);
	return (NULL);
}
