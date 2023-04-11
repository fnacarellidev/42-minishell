/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:38:46 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/11 18:40:15 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	is_redirect(char *str)
{
	if (ft_strcmp(">", str) == 0 || ft_strcmp(">>", str) == 0 \
		|| ft_strcmp("<", str) == 0 || ft_strcmp("<<", str) == 0)
		return (1);
	return (0);
}
