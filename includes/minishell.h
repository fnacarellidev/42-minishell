/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:17:56 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/26 15:49:11 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_H
# define MINISHELL_H
# define SINGLE_QUOTE 39
# define DOUBLE_QUOTE 34
# define DEL_ASCII 127
# define SET1 " \t\v\n\f\r"
# define TMPFILE ".tmpheredoc"
# define READ_END 0
# define WR_END 1
# define NO_SUCH_FILE -1
# define DIR_FILE 0
# define REG_FILE 1

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

typedef struct s_command
{
	int		pipe[2];
	int		number_of_args;
	int		input_fd;
	int		output_fd;
	int		error;
	char	*bin_path;
	char	**args;
}	t_command;

typedef struct s_heredoc
{
	int			fd;
	int			heredoc_exited;
	char		*line;
}	t_heredoc;

typedef struct s_minishell
{
	int			status_code;
	int			number_of_cmds;
	char		**envp;
	int			on_fork;
	int			(*builtins[7])(t_command cmd);
	t_heredoc	heredoc;
	t_node		*envp_list;
	t_command	*commands;
}	t_minishell;

extern t_minishell	g_minishell;

char	*get_key_value(t_node *envp_list, char *key);
void	change_value_from_key(t_node **envp_list, char *key, char *new_data);
int		key_exists(t_node *envp_list, char *key);
char	**lexer(char *cmd);

t_node	*get_envp_list(char **envp);
char	**get_matrix_with_key_value(char *env_variable);
char	**get_envp(void);

// Builtins
void	run_builtin(t_command cmd, int (*builtin)(t_command cmd));
int		get_builtin_pos(char *str);
int		ft_pwd(t_command cmd);
int		ft_echo(t_command cmd);
int		ft_cd(t_command cmd);
int		ft_export(t_command cmd);
int		ft_unset(t_command cmd);
int		ft_env(t_command cmd);
int		ft_exit(t_command cmd);

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
void	expand_vars(char **token);

// Executor
void	executor(char **tokens);
void	init_redirects(void);
void	init_commands(char **tokens, int idx);
void	remove_redirects(void);
void	remove_quotes(void);
void	init_bin_path(void);
void	update_number_of_args(void);
int		handle_exec(int idx, t_command *curr);
int		heredoc(t_command *cmd, char *arg);
void	clear_subtokens(char **subtokens);

// Redirect
int		has_error(t_command *cmd);
void	handle_error(t_command *cmd, char *filename);

// Utils
int		is_quote(char c);
int		is_meta_char(char c);
int		is_bash_word(char *str);
int		is_bash_char(char c);
int		is_redirect(char *str);
int		is_input_redirect(char *redirect);
int		is_output_redirect(char *redirect);
int		is_dir(const char *path);
void	append(char **s1, char *s2);
int		is_valid_var(char *str);
void	swap_stream_fd(char *stream, t_command *command, int new_fd);
void	close_fds(void);
void	close_fds_in_child(void);
void	handler(int signal);
void	ft_free_commands(void);
void	ft_free(void *ptr);
int		is_executable(char *cmd);
void	die_child(int heredoc, int exit_code);
int		test_filename(char *filename, char *redirect);
void	update_env(void);
int		count_args(char **tokens);

void	ft_print_stack(t_node *stack);
void	ft_print_matrix(char **matrix);

#endif
