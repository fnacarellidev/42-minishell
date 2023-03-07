NAME = minishell

SRCS_PATH = ./srcs
OBJS_PATH = ./objs
INCS_PATH = ./includes
LIBFT_PATH = ./srcs/libft

FILES =	minishell \
		minicd \
		unset

SRCS	= $(addprefix $(SRCS_PATH)/, $(addsuffix .c, $(FILES)))
OBJS	= $(addprefix $(OBJS_PATH)/, $(addsuffix .o, $(FILES)))

LIBFT_FLAGS = -L $(LIBFT_PATH) -lft
CFLAGS 	= -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS) $(LIBFT_PATH)/libft.a
	cc $(CFLAGS) -lreadline -o $(NAME) $(OBJS) $(LIBFT_FLAGS)

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_PATH)/libft.a:
	make -C $(LIBFT_PATH) --no-print-directory

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_PATH)
	make -C $(LIBFT_PATH) clean --no-print-directory

valg:
	valgrind --suppressions=ignorelibs.txt --leak-check=full ./$(NAME)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
