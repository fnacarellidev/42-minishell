/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 02:31:24 by fnacarel          #+#    #+#             */
/*   Updated: 2022/08/31 17:18:39 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_extended_ascii(char c);

static int	is_extended_ascii(char c)
{
	if (c < 0)
		return (1);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((*(s1 + i) && *(s2 + i)) && i + 1 < n)
	{
		if (*(s1 + i) - *(s2 + i))
			break ;
		i++;
	}
	if (is_extended_ascii(*(s1 + i)) || is_extended_ascii(*(s2 + i)))
		return (1);
	return (*(s1 + i) - *(s2 + i));
}
