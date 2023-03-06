/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:11:24 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/13 22:16:37 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (i < n)
	{
		if (*((unsigned char *) s1 + i) - *((unsigned char *) s2 + i))
		{
			if (*((unsigned char *) s1 + i) - *((unsigned char *) s2 + i) > 0)
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}
