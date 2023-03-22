/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   human_readable_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:43:56 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/22 18:46:27 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	is_meta_char(char c)
{
	if (ft_strchr("><|", c))
		return (1);
	return (0);
}

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

char	*human_readable_cmd(char *cmd)
{
	int		i;
	int		mem_to_alloc;
	char	*fixed_str;
	int		max_spaces_to_insert;

	i = 0;
	max_spaces_to_insert = count_metachars(cmd) * 2;
	mem_to_alloc = max_spaces_to_insert + ft_strlen(cmd) + 2;
	fixed_str = malloc(sizeof(char) * mem_to_alloc);
	ft_bzero(fixed_str, mem_to_alloc);
	ft_strlcpy(fixed_str, cmd, mem_to_alloc);
	while (fixed_str[i])
	{
		if (is_duplicate_meta_char(&fixed_str[i]))
			i += put_spaces_between_duplicate_metachars(&fixed_str[i], i) + 2;
		else if (is_meta_char(fixed_str[i]))
			i += put_spaces(&fixed_str[i], i) + 1;
		else
			i++;
	}
	printf("%s\n", fixed_str);
	free(fixed_str);
	return (NULL);
}
