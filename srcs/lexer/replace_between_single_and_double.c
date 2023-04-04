/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_between_single_and_double.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:38:10 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/04 16:39:09 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	get_pos(char c, char *set)
{
	int	i;

	i = 0;
	while (c != set[i])
		i++;
	return (i);
}

void	replace_between(char *str, char *set1, char *set2)
{
	int		i;
	int		corresponding_position;
	char	quote;

	i = 0;
	quote = '\0';
	while (str[i])
	{
		if (is_quote(str[i]) && quote == '\0')
			quote = str[i];
		else if (quote != '\0' && ft_strchr(set1, str[i]))
		{
			corresponding_position = get_pos(str[i], set1);
			str[i] = set2[corresponding_position];
		}
		else if (str[i] == quote)
			quote = '\0';
		i++;
	}
}
