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

void	handler_heredoc(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		die_child(1, 130);
	}
}

int	ft_strcmpl(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == '\n' && s2[i] == '\0')
		return (0);
	return (s1[i] - s2[i]);
}

static void	get_heredoc_fd(int fd, char *arg)
{
	int	size;

	signal(SIGINT, handler_heredoc);
	while (1)
	{
		write(1, "> ", 2);
		g_minishell.heredoc.line = validate_line();
		if (!g_minishell.heredoc.line || !ft_strcmpl(g_minishell.heredoc.line, arg))
		{
			if (g_minishell.heredoc.line)
				ft_free(g_minishell.heredoc.line);
			else
			{
				printf("bash: warning: here-document delimited by end of file" \
						" (wanted `%s`)\n", arg);
			}
			break ;
		}
		size = ft_strlen(g_minishell.heredoc.line);
		write(fd, g_minishell.heredoc.line, size);
		ft_free(g_minishell.heredoc.line);
	}
	close(fd);
	die_child(1, 0);
}

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
