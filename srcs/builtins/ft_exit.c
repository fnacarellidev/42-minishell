/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:09:36 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/27 13:33:38 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	has_non_numeric_char(char *first_arg)
{
	while (first_arg && *first_arg)
	{
		if (!ft_isdigit(*first_arg) && *first_arg != '-' && *first_arg != '+')
			return (1);
		first_arg++;
	}
	return (0);
}

static int	out_of_range(char *nptr)
{
	int			nptr_len;
	long int	nbr;

	nptr_len = ft_strlen(nptr);
	nbr = ft_latoi(nptr);
	if (nptr_len > 1 && nbr == 0)
		return (1);
	return (0);
}

static int	get_exit_code(t_command cmd)
{
	if (out_of_range(cmd.args[1]))
	{
		ft_printf(STDERR_FILENO, \
				"bash: exit: %s: numeric argument required\n", cmd.args[1]);
		return (2);
	}
	else
		return (ft_latoi(cmd.args[1]));
}

int	ft_exit(t_command cmd)
{
	long int	exit_code;

	exit_code = 0;
	if (cmd.args[1] == NULL)
		die_child(0, exit_code);
	if (has_non_numeric_char(cmd.args[1]))
	{
		ft_printf(STDERR_FILENO, \
			"bash: exit: %s: numeric argument required\n", cmd.args[1]);
		exit_code = 2;
	}
	else if (cmd.number_of_args > 2)
	{
		ft_printf(STDERR_FILENO, "bash: exit: too many arguments\n");
		exit_code = 1;
	}
	else
		exit_code = get_exit_code(cmd);
	ft_putstr_fd("exit\n", STDIN_FILENO);
	die_child(0, exit_code);
	return (0);
}
