/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:17:56 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/28 16:01:57 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_H
# define MINISHELL_H
# define SINGLE_QUOTE 39
# define DOUBLE_QUOTE 34
# define DEL_ASCII 127

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

typedef struct s_minishell
{
	int		status_code;
	t_node	*envp;
}	t_minishell;

extern t_minishell	g_minishell;

char	*get_key_value(t_node *envp_list, char *key);
void	change_value_from_key(t_node **envp_list, char *key, char *new_data);
int		key_exists(t_node *envp_list, char *key);
char	**lexer(char *cmd);

t_node	*get_envp_list(char **envp);

// Lexer
int		put_spaces(char *str, int pos);
int		space_duplicate_metachars(char *str, int pos);
char	*human_readable_cmd(char *cmd);
void	erase_empty_quotes(char *str);
void	replace_between(char *str, char c1, char c2);

// Parser
int		parser(char **tokens);
int		get_syntax_error_idx(char **tokens);

// Utils
int		is_quote(char c);
int		is_meta_char(char c);
int		is_bash_word(char *str);

#endif
