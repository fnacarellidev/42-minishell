NAME = 			minishell

SRCS_PATH =		./srcs
LIBFT_PATH =	./srcs/libft

FILES =			minishell \
				lexer/lexer

SRCS =			$(addprefix $(SRCS_PATH)/, $(addsuffix .c, $(FILES)))
OBJS =			$(addprefix $(SRCS_PATH)/, $(addsuffix .o, $(FILES)))

LIBFT_FLAGS =	-L $(LIBFT_PATH) -lft
CFLAGS = 		-Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_PATH)/libft.a
	cc $(CFLAGS) -lreadline -o $(NAME) $(OBJS) $(LIBFT_FLAGS)

%.o: %.c
	cc $(CFLAGS) ./includes -c $< -o $@

$(LIBFT_PATH)/libft.a:
	make -C $(LIBFT_PATH) --no-print-directory

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean --no-print-directory

valg: $(NAME)
	valgrind --suppressions=ignorelibs.txt --leak-check=full ./$(NAME)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
