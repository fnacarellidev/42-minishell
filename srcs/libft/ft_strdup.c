/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 22:26:47 by fnacarel          #+#    #+#             */
/*   Updated: 2022/08/31 22:34:34 by fnacarel         ###   ########.fr       */
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
	while (*(s + i))
	{
		*(dup + i) = *(s + i);
		i++;
	}
	*(dup + i) = '\0';
	return (dup);
}
