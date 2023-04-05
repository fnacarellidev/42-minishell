NAME = 			minishell

SRCS_PATH =		./srcs
OBJS_PATH =		./objs
LIBFT_PATH =	./srcs/libft

FILES =			minishell \
				lexer/lexer \
				lexer/space_cmd \
				lexer/human_readable_cmd \
				lexer/replace_between_single_and_double \
				parser/parser \
				parser/get_syntax_error_idx \
				parser/subtokens \
				aux_funcs/is_quote \
				aux_funcs/is_metachar \
				aux_funcs/is_bash_word \
				aux_funcs/is_bash_char \
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

valg: $(NAME)
	valgrind --suppressions=ignorelibs.txt --leak-check=full --show-leak-kinds=all ./$(NAME)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
