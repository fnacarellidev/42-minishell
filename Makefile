NAME = 			minishell

SRCS_PATH =		./srcs
OBJS_PATH =		./objs
LIBFT_PATH =	./srcs/libft

FILES =			minishell \
				builtins/run_builtin \
				builtins/get_builtin_pos \
				builtins/ft_echo \
				builtins/ft_pwd \
				builtins/ft_cd \
				builtins/ft_export \
				builtins/ft_unset \
				builtins/ft_env \
				builtins/ft_exit \
				lexer/lexer \
				lexer/space_cmd \
				lexer/human_readable_cmd \
				lexer/replace_between_single_and_double \
				parser/parser \
				parser/get_syntax_error_idx \
				parser/expand_vars \
				executor/executor \
				executor/remove_redirects \
				executor/remove_quotes \
				executor/init_commands \
				executor/init_bin_path \
				executor/run_n_cmds \
				executor/update_number_of_args \
				redirects/handle_redirect_errors \
				redirects/heredoc \
				redirects/init_redirects \
				aux_funcs/is_quote \
				aux_funcs/is_metachar \
				aux_funcs/is_bash_word \
				aux_funcs/is_bash_char \
				aux_funcs/ft_append \
				aux_funcs/is_valid_var \
				aux_funcs/swap_fd \
				aux_funcs/close_fds \
				aux_funcs/die_child \
				aux_funcs/is_redirect \
				aux_funcs/free_commands \
				aux_funcs/handler \
				aux_funcs/print \
				aux_funcs/ft_free \
				aux_funcs/is_dir \
				aux_funcs/test_filename \
				aux_funcs/update_env \
				aux_funcs/count_args \
				aux_funcs/make_dups \
				aux_funcs/print_curr_err \
				manipulate_envp \
				get_envp_list

SRCS =			$(addprefix $(SRCS_PATH)/, $(addsuffix .c, $(FILES)))
OBJS =			$(addprefix $(OBJS_PATH)/, $(addsuffix .o, $(FILES)))

LIBFT_FLAGS =	-L $(LIBFT_PATH) -lft
CFLAGS = 		-Wall -Wextra -Werror -g3

all: libft $(NAME)

libft:
	@make -C $(LIBFT_PATH) --no-print-directory

$(NAME): $(OBJS) $(LIBFT_PATH)/libft.a
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) -lreadline

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	@mkdir -p $(@D)
	cc $(CFLAGS) -I ./includes -c $< -o $@

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(LIBFT_PATH)/libft.a:
	make -C $(LIBFT_PATH) --no-print-directory

clean:
	rm -rf $(OBJS_PATH)
	make -C $(LIBFT_PATH) clean --no-print-directory

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
