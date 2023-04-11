/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:17:56 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/11 15:21:40 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_H
# define MINISHELL_H
# define SINGLE_QUOTE 39
# define DOUBLE_QUOTE 34
# define DEL_ASCII 127
# define SET1 " \t\v\n\f\r"

# include <term.h>
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
# include "errors.h"
# include "../srcs/libft/libft.h"

typedef struct s_pipeline
{
	int		input_fd;
	int		output_fd;
}	t_pipeline;

typedef struct s_minishell
{
	int			status_code;
	t_node		*envp;
	t_pipeline	pipeline;
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
void	replace_between(char *str, char *set1, char *set2);

// Parser
int		parser(char **tokens);
int		get_syntax_error_idx(char **tokens);
void	expand_token(char **token);
char	**get_subtokens(char *token, int idx);
char	*concat_subtokens(char **subtokens);
void	erase_empty_quotes_and_ext_quotes(char **tokens);

// Executor
void	executor(char **tokens);
int		validate_redirects(char **tokens);
void	init_redirects(char **tokens);
int		heredoc(char *arg);

// Utils
int		is_quote(char c);
int		is_meta_char(char c);
int		is_bash_word(char *str);
int		is_bash_char(char c);
void	append(char **s1, char *s2);
int		is_valid_var(char *str);

#endif
