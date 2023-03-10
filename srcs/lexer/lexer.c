/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:57:20 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/10 20:19:46 by fnacarel         ###   ########.fr       */
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

// Receives the pointer to the position of a metacharacter, changed previous
// and next position to spaces if it needs to, but before doing that, it 
// shifts the string so it won't lose any data when writing the ' ' char
int	put_spaces(char *str, int position_of_whole_string)
{
	int	i;

	i = 0;
	if (position_of_whole_string != 0 && *(str - 1) != ' ')
	{
		ft_memmove(str + 1, str, ft_strlen(str));
		str[0] = ' ';
		i++;
		if (str[2] != ' ')
		{
			ft_memmove(str + 3, str + 2, ft_strlen(str));
			str[2] = ' ';
			i++;
		}
	}
	else if (str[1] != ' ')
	{
		ft_memmove(str + 2, str + 1, ft_strlen(str));
		str[1] = ' ';
		i++;
	}
	return (i);
}
