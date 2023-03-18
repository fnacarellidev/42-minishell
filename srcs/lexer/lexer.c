/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:57:20 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/17 21:59:37 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static int	is_meta_char(char c)
{
	int		i;
	char	metachars[3] = {'>', '<', '|'};

	i = 0;
	while (i < 3)
	{
		if (c == metachars[i])
			return (1);
		i++;
	}
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
		if (is_meta_char(cmd[i]) && cmd[i] == cmd[i + 1])
		{
			amount_of_metachars++;
			i++;
		}
		else if (is_meta_char(cmd[i]))
			amount_of_metachars++;
		i++;
	}
	return (amount_of_metachars);
}

// Receives the pointer to the position of a metacharacter, changed previous
// and next position to spaces if it needs to, but before doing that, it 
// shifts the string so it won't lose any data when writing the ' ' char
int	put_spaces(char *str, int position_of_whole_string)
{
	int	i;

	i = 0;
	if (position_of_whole_string != 0 && *(str - 1) != ' ')
	{
		ft_memmove(str + 1, str, ft_strlen(str));
		str[0] = ' ';
		i++;
		if (str[2] != ' ')
		{
			ft_memmove(str + 3, str + 2, ft_strlen(str));
			str[2] = ' ';
			i++;
		}
	}
	else if (str[1] != ' ')
	{
		ft_memmove(str + 2, str + 1, ft_strlen(str));
		str[1] = ' ';
		i++;
	}
	return (i);
}

int	put_spaces_between_duplicate_metachars(char *str, int position_of_whole_string)
{
	int	i;

	i = 0;
	if (position_of_whole_string != 0 && *(str - 1) != ' ')
	{
		ft_memmove(str + 1, str, ft_strlen(str));
		str[0] = ' ';
		i++;
		if (str[3] != ' ')
		{
			ft_memmove(str + 4, str + 3, ft_strlen(str));
			str[3] = ' ';
			i++;
		}
	}
	else if (str[2] != ' ')
	{
		ft_memmove(str + 3, str + 2, ft_strlen(str));
		str[2] = ' ';
		i++;
	}
	return (i);
}

char	*format_cmd(char *cmd)
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
		if (is_meta_char(fixed_str[i]) && fixed_str[i] == fixed_str[i + 1])
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

char	**lexer(char *cmd)
{
	format_cmd(cmd);
	return (NULL);
}
