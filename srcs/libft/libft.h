/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:02:44 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/06 15:51:49 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifdef __linux__
#  define NULLABLE "(nil)"
# else
#  define NULLABLE "0x0"
# endif

# define HEX_LWCASE "0123456789abcdef"
# define HEX_UPCASE "0123456789ABCDEF"
# define DEC_DIGITS "0123456789"

// ft_printf stuff
int		ft_printf(const char *str, ...);
int		ft_putstr_printf(char *str);
int		put_base_printf(long long nbr, char *base);
int		puthex_printf(unsigned long long nbr, int use_uppercase);
int		ft_put_address(unsigned long long nbr);
int		putchar_printf(char c);
size_t	ft_strlen_printf(char *str);

typedef struct s_node
{
	char			*data;
	struct s_node	*next;
}				t_node;
void	ft_free_list(t_node **head);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
int		ft_lstsize(t_node *lst);
int		ft_count_matrix(void **matrix);
int		ft_power(int base, int exponent);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putnbr_fd(int n, int fd);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstdelone(t_node *lst, void (*del)(void *));
void	ft_lstclear(t_node **lst, void (*del)(void *));
void	ft_lstiter(t_node *lst, void (*f)(void *));
void	ft_putnbr_base(long long nbr, char *base);
void	ft_putchar(char c);
void	ft_free_matrix(void **matrix);
void	ft_free_spatial_matrix(void ***matrix);
void	ft_free_matrix_size_n(void **matrix, int size);
void	ft_swap(int *a, int *b);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
t_node	*ft_lstnew(void *content);
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void *));

#endif
