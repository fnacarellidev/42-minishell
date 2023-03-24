/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_between_single_and_double.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:38:10 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/24 19:23:56 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void	replace_between(char *str, char c1, char c2)
{
	int		i;
	char	quote;

	i = 0;
	quote = '\0';
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && quote == '\0')
			quote = str[i];
		else if (quote != '\0' && str[i] == c1)
			str[i] = c2;
		else if (str[i] == quote)
			quote = '\0';
		i++;
	}
}
