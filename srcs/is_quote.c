/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:24:25 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/24 20:24:57 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

int	is_quote(char c)
{
	if (c == SINGLE_QUOTE || c == DOUBLE_QUOTE)
		return (1);
	return (0);
}
