/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 01:52:48 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/19 19:43:11 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*first_occurence;

	i = 0;
	first_occurence = 0;
	if (!s)
		return (NULL);
	while (*(s + i))
	{
		if (*(s + i) == (unsigned char) c)
		{
			first_occurence = (s + i);
			return ((char *) first_occurence);
		}
		i++;
	}
	if (c == 0)
		first_occurence = (s + ft_strlen(s));
	return ((char *) first_occurence);
}
