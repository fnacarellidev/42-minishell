NAME = minishell

SRCS_PATH = ./srcs
OBJS_PATH = ./objs
INCS_PATH = ./includes

FILES	= minishell

SRCS	= $(addprefix $(SRCS_PATH)/, $(addsuffix .c, $(FILES)))
OBJS	= $(addprefix $(OBJS_PATH)/, $(addsuffix .o, $(FILES)))

CFLAGS 	= -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS)
	cc $(CLAGS) -o $(NAME) $(OBJS)

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
