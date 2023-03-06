/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:14:22 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/13 22:05:21 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			*((char *) dest + i) = *((char *) src + i);
		}
	}
	return (dest);
}
