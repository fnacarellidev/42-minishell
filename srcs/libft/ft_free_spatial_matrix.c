/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_spatial_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:51:14 by fnacarel          #+#    #+#             */
/*   Updated: 2022/12/15 15:09:32 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_free_spatial_matrix(void ***matrix)
{
	int	i;
	int	j;
	int	matr_len;

	i = 0;
	matr_len = ft_count_matrix(*matrix);
	while (i < matr_len)
	{
		j = 0;
		while (matrix[i][j])
		{
			free(matrix[i][j]);
			j++;
		}
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
