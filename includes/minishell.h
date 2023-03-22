/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:17:56 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/22 18:51:53 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_H
# define MINISHELL_H

# include <term.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <curses.h>
# include <termios.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "../srcs/libft/libft.h"

char	*get_key_value(t_node *envp_list, char *key);
void	change_value_from_key(t_node **envp_list, char *key, char *new_data);
int		key_exists(t_node *envp_list, char *key);
char    **lexer(char *cmd);

t_node	*get_envp_list(char **envp);

// Lexer
int		put_spaces(char *str, int position_of_whole_string);

#endif
