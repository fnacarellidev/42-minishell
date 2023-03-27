/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   human_readable_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:43:56 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/27 15:27:31 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	is_duplicate_meta_char(char *str)
{
	if (*str != '|' && (is_meta_char(*str) && *str == *(str + 1)))
		return (1);
	return (0);
}

static int	count_metachars(char *cmd)
{
	int		i;
	int		amount_of_metachars;

	i = 0;
	amount_of_metachars = 0;
	while (cmd[i])
	{
		if (is_meta_char(cmd[i]))
			amount_of_metachars++;
		i++;
	}
	return (amount_of_metachars);
}

char	*init_human_readable_cmd(char *cmd)
{
	char	*new_cmd;
	int		mem_to_alloc;
	int		max_spaces_to_insert;

	max_spaces_to_insert = count_metachars(cmd) * 2;
	mem_to_alloc = max_spaces_to_insert + ft_strlen(cmd) + 2;
	new_cmd = malloc(sizeof(char) * mem_to_alloc);
	ft_bzero(new_cmd, mem_to_alloc);
	ft_strlcpy(new_cmd, cmd, mem_to_alloc);
	return (new_cmd);
}

static void	put_space_if_needed(char *cmd, int *i)
{
	if (is_duplicate_meta_char(&cmd[*i]))
		*i += put_spaces_between_duplicate_metachars(&cmd[*i], *i) + 2;
	else if (is_meta_char(cmd[*i]))
		*i += put_spaces(&cmd[*i], *i) + 1;
}

char	*human_readable_cmd(char *cmd)
{
	int		i;
	char	quoted;
	char	*new_cmd;

	i = 0;
	quoted = '\0';
	new_cmd = init_human_readable_cmd(cmd);
	while (new_cmd[i])
	{
		if (is_quote(new_cmd[i]) && quoted == '\0')
		{
			quoted = new_cmd[i];
			i++;
		}
		else if (quoted == '\0' && is_meta_char(new_cmd[i]))
			put_space_if_needed(new_cmd, &i);
		else if (quoted == new_cmd[i])
		{
			quoted = '\0';
			i++;
		}
		else
			i++;
	}
	return (new_cmd);
}
