/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:57:20 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/23 14:50:16 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void    replace_between(char *str, char c1, char c2, char c3)
{
	int	i;
	int	in_between;

	i = 0;
	in_between = 0;
	while (str[i])
	{
		if (str[i] == c2)
			in_between = !in_between;
		else if (in_between && str[i] == c1)
			str[i] = c3;
		i++;
	}
}

char	**lexer(char *cmd)
{
	char	*str;

	str = human_readable_cmd(cmd);
	printf("%s\n", str);
	free(str);
	return (NULL);
}
