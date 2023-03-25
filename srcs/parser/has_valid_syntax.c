/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:07:54 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/25 18:05:33 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	is_preceeded_or_followed_by_metachar(char **tokens, int pos)
{
	if (is_meta_char(*tokens[pos - 1]) || is_meta_char(*tokens[pos + 1]))
		return (1);
	return (0);
}
