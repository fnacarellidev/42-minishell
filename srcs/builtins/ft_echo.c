/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:20:08 by revieira          #+#    #+#             */
/*   Updated: 2023/04/24 18:07:37 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	print_args(int size, char **args)
{
	int	i;

	i = 1;
	if (ft_strcmp(args[1], "-n") == 0)
		i++;
	while (i < size)
	{
		printf("%s", args[i]);
		if (i != size - 1)
			printf(" ");
		i++;
	}
}

int	ft_echo(t_command cmd)
{
	int	comparison;

	comparison = 1;
	if (cmd.number_of_args < 2)
		printf("\n");
	else
	{
		comparison = ft_strcmp(cmd.args[1], "-n");
		print_args(cmd.number_of_args, cmd.args);
		if (comparison != 0)
			printf("\n");
	}
	if (g_minishell.on_fork)
		exit(0);
	return (0);
}
