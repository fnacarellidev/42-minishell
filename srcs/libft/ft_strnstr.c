/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:59:17 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/12 18:29:05 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *) big);
	while (*(big + i) && i < len)
	{
		if (*(big + i) == *(little + 0))
		{
			j = 0;
			while (*(big + i + j) == *(little + j) && \
					(*(big + i + j) && *(little + j)))
			{
				if (i + j >= len)
					return (NULL);
				j++;
			}
			if (j == ft_strlen(little))
				return ((char *) big + i);
		}
		i++;
	}
	return (NULL);
}
