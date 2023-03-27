/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:54:18 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/27 13:13:49 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	parser(char **tokens)
{
	minishell.status_code = 0;
	has_valid_syntax(tokens);
	printf("status_code: %d\n", minishell.status_code);
	return (0);
}
