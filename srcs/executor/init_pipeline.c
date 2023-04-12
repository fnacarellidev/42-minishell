/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:14:37 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/12 15:11:18 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	count_commands(char **tokens)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tokens[i])
	{
		if (ft_strcmp("|", tokens[i]) == 0)
			j++;
		i++;
	}
	return (j + 1);
}
