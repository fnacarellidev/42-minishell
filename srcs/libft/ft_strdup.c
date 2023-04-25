/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 22:26:47 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/25 17:40:48 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len_s;
	int		i;
	char	*dup;

	i = 0;
	len_s = ft_strlen(s);
	dup = (char *) malloc((len_s * sizeof(char)) + 1);
	if (s)
	{
		while (*(s + i))
		{
			*(dup + i) = *(s + i);
			i++;
		}
	}
	*(dup + i) = '\0';
	return (dup);
}
