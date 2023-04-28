/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:20:08 by revieira          #+#    #+#             */
/*   Updated: 2023/04/28 10:16:07 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static void	print_args(int size, char **args, int out_fd)
{
	int	i;

	i = 1;
	if (ft_strcmp(args[1], "-n") == 0)
		i++;
	while (i < size - 1)
	{
		ft_putstr_fd(args[i], out_fd);
		ft_putstr_fd(" ", out_fd);
		i++;
	}
	if (args[i])
		ft_putstr_fd(args[i], out_fd);
}

int	ft_echo(t_command cmd)
{
	int	comparison;
	int	out;

	out = 1;
	handle_output(cmd, &out);
	comparison = 1;
	if (g_minishell.on_fork && (cmd.input_fd == -1 || cmd.output_fd == -1))
		die_child(0, 1);
	if (!g_minishell.on_fork && (cmd.input_fd == -1 || cmd.output_fd == -1))
		return (1);
	if (cmd.number_of_args < 2)
		ft_putstr_fd("\n", out);
	else
	{
		comparison = ft_strcmp(cmd.args[1], "-n");
		print_args(cmd.number_of_args, cmd.args, out);
		if (comparison != 0)
			ft_putstr_fd("\n", out);
	}
	if (g_minishell.on_fork)
		die_child(0, 0);
	return (0);
}
