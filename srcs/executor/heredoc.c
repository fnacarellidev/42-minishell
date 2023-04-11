/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:08:24 by revieira          #+#    #+#             */
/*   Updated: 2023/04/11 17:33:11 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

{
	int		fd;
	char	*delimiter;
	char	*line;

	fd = open(TMPFILE, O_CREAT | O_WRONLY, 0644);
	delimiter = ft_strjoin(arg, "\n");
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (!line || !ft_strcmp(line, delimiter))
		{
			if (line)
				free(line);
			else
				here_doc_err(arg);
			free(delimiter);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	close(fd);
	fd = open(TMPFILE, O_RDWR);
	return (fd);
}
