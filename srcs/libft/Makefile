NAME = libft.a

CFLAGS = -Wall -Wextra -Werror
CFILES =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memmove.c \
			ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
			ft_strnstr.c ft_calloc.c ft_strdup.c ft_atoi.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_substr.c ft_strjoin.c ft_striteri.c \
			ft_strmapi.c ft_itoa.c ft_putnbr_fd.c  ft_strtrim.c ft_split.c \
			ft_putstr.c ft_putchar.c ft_putnbr_base.c \
			ft_printf.c ft_printf_utils.c ft_count_matrix.c ft_free_matrix.c \
			ft_free_spatial_matrix.c ft_free_matrix_size_n.c ft_swap.c ft_power.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_free_list.c \
			ft_strcmp.c

OBJS = $(CFILES:%.c=%.o)
	   
all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:%.c
	cc $(FLAGS) -I ./includes -c $< -o $@

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJS)

re : fclean all
