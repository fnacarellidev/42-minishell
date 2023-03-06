/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:06:26 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/06 15:38:28 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last_node;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last_node = ft_lstlast(*lst);
			last_node -> next = new;
		}
	}
}
