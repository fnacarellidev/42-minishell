/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:08:24 by revieira          #+#    #+#             */
/*   Updated: 2023/04/11 15:21:51 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

int	heredoc(char *arg)
{
	int		tmpfile;
	char	*delimiter;
	char	*line;

	tmpfile = open(".tmpheredoc", O_CREAT | O_WRONLY, 0644);
	delimiter = ft_strjoin(arg, "\n");
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);	
		if (!line || !ft_strcmp(line, delimiter))
		{
			if (line)
				free(line);
			free(delimiter);
			break ;
		}
		write(tmpfile, line, ft_strlen(line));
		free(line);
	}
	close(tmpfile);
	tmpfile = open(".tmpheredoc", O_RDWR);
	return (tmpfile);
}
