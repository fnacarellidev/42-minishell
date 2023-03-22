/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:48:25 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/22 18:51:45 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

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
