/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:54:34 by revieira          #+#    #+#             */
/*   Updated: 2023/04/25 15:21:12 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	exec_unset(char *delet_var)
{
	if (!is_valid_identifier(delet_var))
	{
		printf("bash: unset: `%s': not a valid identifier\n", delet_var);
		return (1);
	}
	if (key_exists(g_minishell.envp_list, delet_var))
	{
		delet_specific_node(&g_minishell.envp_list, delet_var);
		update_env();
	}
	return (0);
}

int	ft_unset(t_command cmd)
{
	int	i;
	int	status;

	i = 1;
	status = 0;
	if (cmd.number_of_args > 1)
	{
		while (cmd.args[i])
		{
			if (exec_unset(cmd.args[i]))
				status = 1;
			i++;
		}
	}
	return (status);
}
