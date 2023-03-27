/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:54:18 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/27 13:53:20 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	parser(char **tokens)
{
	has_valid_syntax(tokens);
	printf("status_code: %d\n", minishell.status_code);
	return (0);
}
