/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_empty_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:17:10 by revieira          #+#    #+#             */
/*   Updated: 2023/03/23 14:48:04 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static char	*find_subsequent_quotes(char *str)
{
	while (*str)
	{
		if ((*str == SINGLE_QUOTE || *str == DOUBLE_QUOTE) && str[1] == *str)
			return (str);
		str++;
	}
	return (NULL);
}
