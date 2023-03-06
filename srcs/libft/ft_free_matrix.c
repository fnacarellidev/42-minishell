/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:53:23 by fnacarel          #+#    #+#             */
/*   Updated: 2022/12/15 15:03:17 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_free_matrix(void **matrix)
{
	int	i;
	int	matrix_len;

	i = 0;
	matrix_len = ft_count_matrix(matrix);
	while (i < matrix_len)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
