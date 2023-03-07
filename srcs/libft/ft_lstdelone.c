/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:07:43 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/07 15:36:31 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstdelone(t_node *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->key);
		del(lst->value);
		free(lst);
	}
}
