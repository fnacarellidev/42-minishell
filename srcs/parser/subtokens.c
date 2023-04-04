/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtokens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:24:12 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/04 17:04:40 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	count_subtokens(char *token)
{
	int	i;
	int	subtokens;
	int	quote;

	i = 0;
	subtokens = 0;
	while (token[i])
	{
		subtokens++;
		if (is_quote(token[i]))
		{
			quote = token[i++];
			while (quote != token[i])
				i++;
			i++;
		}
		else
		{
			while (!is_quote(token[i]) && token[i])
				i++;
		}
	}
	return (subtokens);
}
