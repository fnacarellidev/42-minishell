/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:23:27 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/13 22:36:13 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		memory_allocated;

	if (start > ft_strlen(s))
	{
		substr = (char *) malloc(1);
		*substr = 0;
		return (substr);
	}
	else if (ft_strlen(s) > len)
		memory_allocated = len + 1;
	else
		memory_allocated = ft_strlen(s) - start + 1;
	substr = (char *) malloc(sizeof(char) * memory_allocated);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, memory_allocated);
	return (substr);
}
