/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:25:25 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/06 15:39:41 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst -> next != 0)
		lst = lst -> next;
	return (lst);
}
