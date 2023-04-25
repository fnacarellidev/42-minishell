/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_latoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:47:25 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/25 15:30:44 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	ft_issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int	ft_isnumber(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

long int	ft_latoi(const char *nptr)
{
	int			i;
	long int	res;
	int			sign;

	sign = 1;
	i = 0;
	res = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (!ft_isnumber(nptr[i]) && !ft_issign(nptr[i]))
		return (res);
	if (ft_issign(nptr[i]))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isnumber(nptr[i]))
	{
		if (((res * sign * 10) + (nptr[i] - '0') * sign) / 10 != res * sign)
			return (0);
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}
