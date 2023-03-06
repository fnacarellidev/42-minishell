/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:00:54 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/21 19:45:46 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_strcpy(char *dest, const char *src);

static void	ft_strcpy(char *dest, const char *src)
{
	int		i;
	size_t	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (*(src + i))
	{
		*(dest + dest_len + i) = *(src + i);
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*finalstr;

	finalstr = ft_calloc(1, ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!finalstr)
		return (NULL);
	ft_strcpy(finalstr, s1);
	ft_strcpy(finalstr, s2);
	*(finalstr + ft_strlen(s1) + ft_strlen(s2)) = '\0';
	return (finalstr);
}
