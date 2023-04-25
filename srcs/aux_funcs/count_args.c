/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:49:25 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/25 19:49:35 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	count_args(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] && ft_strcmp("|", tokens[i]) != 0)
		i++;
	return (i);
}
