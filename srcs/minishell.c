/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:12:01 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/06 19:09:25 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"
#include "libft/libft.h"

int main()
{
	char	*line;

	while (1)
	{
		line = readline("$ ");
		if (ft_strlen(line) != 0)
			add_history(line);
		if (ft_strlen(line) > 0 && ft_strncmp(line, "exit\n", ft_strlen(line)) == 0)
		{
			free(line);
			exit(0);
		}
		free(line);
	}
	return (0);
}
