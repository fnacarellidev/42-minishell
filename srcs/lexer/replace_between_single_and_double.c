/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_between_single_and_double.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:38:10 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/23 15:48:08 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	replace_between(char *str, char c1, char c2, char c3)
{
	int	i;
	int	in_between;

	i = 0;
	in_between = 0;
	while (str[i])
	{
		if (str[i] == c2)
			in_between = !in_between;
		else if (in_between && str[i] == c1)
			str[i] = c3;
		i++;
	}
}
