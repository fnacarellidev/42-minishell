/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:00:38 by revieira          #+#    #+#             */
/*   Updated: 2023/04/02 01:09:14 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = (char *) malloc(sizeof(char) * n + 1);
	while (*(s + i) && i < n)
	{
		*(dup + i) = *(s + i);
		i++;
	}
	*(dup + i) = '\0';
	return (dup);
}
