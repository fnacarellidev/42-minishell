/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:57:20 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/22 20:13:29 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

char	**lexer(char *cmd)
{
	char	*str;

	str = human_readable_cmd(cmd);
	printf("%s\n", str);
	free(str);
	return (NULL);
}
