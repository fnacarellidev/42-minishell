/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:07:43 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/25 16:41:25 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstdelone(t_node *lst, void (*del)(void *))
{
	if (lst && del)
	{
		if (lst->key)
			del(lst->key);
		if (lst->value)
			del(lst->value);
		if (lst->env_line)
			del(lst->env_line);
		free(lst);
	}
}
