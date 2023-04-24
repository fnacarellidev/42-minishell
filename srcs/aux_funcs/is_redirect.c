/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:38:46 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/24 14:32:41 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	is_output_redirect(char *redirect)
{
	if (ft_strcmp(redirect, ">") == 0 || ft_strcmp(redirect, ">>") == 0)
		return (1);
	return (0);
}

int	is_input_redirect(char *redirect)
{
	if (ft_strcmp(redirect, "<") == 0 || ft_strcmp(redirect, "<<") == 0)
		return (1);
	return (0);
}

int	is_redirect(char *str)
{
	if (ft_strcmp(">", str) == 0 || ft_strcmp(">>", str) == 0 \
		|| ft_strcmp("<", str) == 0 || ft_strcmp("<<", str) == 0)
		return (1);
	return (0);
}
