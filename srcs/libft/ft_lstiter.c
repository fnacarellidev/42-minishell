/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:13:27 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/07 15:36:57 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_node *lst, void (*f)(void *))
{
	if (f)
	{
		while (lst)
		{
			f(lst->key);
			f(lst->value);
			lst = lst -> next;
		}
	}
}
