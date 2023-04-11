/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_without_redirects.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:36:32 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/11 18:52:37 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	exclude_redirects(char **tokens)
{
	int	i;
	int	mem_to_alloc;

	i = 0;
	mem_to_alloc = 0;
	while (tokens[i])
	{
		if (is_redirect(tokens[i]))
			i++;
		else
			mem_to_alloc++;
		i++;
	}
	return (mem_to_alloc);
}

static void	copy_tokens(char **new, char **copy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (copy[i])
	{
		if (is_redirect(copy[i]))
			i++;
		else
			new[j++] = ft_strdup(copy[i]);
		i++;
	}
}
