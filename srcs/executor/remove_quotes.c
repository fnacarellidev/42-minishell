/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:39:44 by revieira          #+#    #+#             */
/*   Updated: 2023/04/13 14:47:10 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	is_empty_quote(char *str)
{
	if (*str == str[1])
		return (1);
	return (0);
}

static void	erase_external_quotes(char *str)
{
	int	last_pos;
	int	str_len;

	str_len = ft_strlen(str);
	ft_memmove(str, str + 1, str_len);
	last_pos = str_len - 2;
	ft_memset(str + last_pos, 0, 1);
}

static void	clear_subtokens(char **subtokens)
{
	int	i;

	i = 0;
	while (subtokens[i])
	{
		if (is_quote(*subtokens[i]) && is_empty_quote(subtokens[i]))
			ft_memset(subtokens[i], 0, 2);
		else if (is_quote(*subtokens[i]))
			erase_external_quotes(subtokens[i]);
		i++;
	}
}

static void	erase_empty_quotes_and_ext_quotes(char **tokens)
{
	int		i;
	char	**subtokens;

	i = 0;
	while (tokens[i] != NULL)
	{
		subtokens = get_subtokens(tokens[i], 0);
		clear_subtokens(subtokens);
		free(tokens[i]);
		tokens[i] = concat_subtokens(subtokens);
		free(subtokens);
		i++;
	}
}

void	remove_quotes(void)
{
	int	i;
	int	args;

	i = 0;
	args = g_minishell.number_of_cmds;
	while (i < args)
	{
		erase_empty_quotes_and_ext_quotes(g_minishell.commands[i].args);	
		i++;
	}
}
