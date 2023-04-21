/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:08:24 by revieira          #+#    #+#             */
/*   Updated: 2023/04/21 13:37:51 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

static char	*validate_line(void)
{
	char	*line;

	line = get_next_line(0);
	if (!line)
		return (NULL);
	expand_vars(&line);
	return (line);
}

int	get_heredoc_fd(char *arg)
{
	int		fd;
	char	*delimiter;
	char	*line;

	fd = open(TMPFILE, O_CREAT | O_WRONLY, 0644);
	delimiter = ft_strjoin(arg, "\n");
	while (1)
	{
		write(1, "> ", 2);
		line = validate_line();
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

int	heredoc(t_command *cmd, char *arg)
{
	int		pid;
	int		status;

	g_minishell.heredoc.on_heredoc = 1;
	g_minishell.heredoc.fd = open(TMPFILE, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	pid = fork();
	if (pid == 0)
		get_heredoc_fd(g_minishell.heredoc.fd, arg);
	waitpid(pid, &status, 0);
	g_minishell.heredoc.on_heredoc = 0;
	close(g_minishell.heredoc.fd);
	if (status != 0)
		return (-1);
	swap_stream_fd("input", cmd, open(TMPFILE, O_RDWR));
	return (0);
}
