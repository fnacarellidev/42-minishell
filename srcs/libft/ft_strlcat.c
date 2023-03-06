/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:36:18 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/13 22:06:31 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dst;

	i = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (size < len_dst)
		return (len_src + size);
	while (*(src + i) && i + 1 < (size - len_dst))
	{
		*(dst + len_dst + i) = *(src + i);
		i++;
	}
	*(dst + len_dst + i) = '\0';
	return (len_dst + len_src);
}
