/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:57:49 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/15 12:20:56 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (!nmemb || !size || (nmemb * size) / size != nmemb)
		return (NULL);
	ptr = (void *) malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < size * nmemb)
	{
		*((char *) ptr + i) = '\0';
		i++;
	}
	return (ptr);
}
