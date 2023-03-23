/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:57:20 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/23 13:56:24 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

char	*get_empty_surrounder(char *str, char c1)
{
	while (*str)
	{
		if (*str == c1 && *(str + 1) == c1)
			return (str);
		str++;
	}
	return (NULL);
}

void	erase_surrounder(char *str)
{
	int	len_str;

	len_str = ft_strlen(str);
	if (str[2] == '\0')
	{
		str[0] = '\0';
		return ;
	}
	ft_memmove(str, str + 2, len_str - 2);
	str[len_str - 2] = '\0';
}

char	**lexer(char *cmd)
{
	char	*str;

	str = human_readable_cmd(cmd);
	printf("%s\n", str);
	free(str);
	return (NULL);
}
