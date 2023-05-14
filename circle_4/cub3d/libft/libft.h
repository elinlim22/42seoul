/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:57:54 by dongyoki          #+#    #+#             */
/*   Updated: 2023/02/23 19:06:50 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "gc/garbage_collector.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_list
{
	char			*str;
	int				x_size;
	int				y_size;
	struct s_list	*next;
}					t_list;

// Libc functions
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t dstsize);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(char *s1, char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
bool				ft_atoi(const char *nptr, int *num);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);

// Additional functions
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
int					ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// Bonus part
t_list				*ft_lstnew(char *content, int y);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// ft_printf

// ft_printf.c
int					ft_printf(const char *str, ...);
int					parse(const char *str, va_list *ap, ssize_t *sum,
						char **line);
int					process(char **line, ssize_t *sum, char flag, va_list *ap);

// ft_strjoinchr.c
int					ft_strjoin_print(char **line, char c, ssize_t *sum);

// _c_s_per.c
int					_c(va_list *ap, char **line, ssize_t *sum);
int					_s(va_list *ap, char **line, ssize_t *sum);
int					_per(char **line, ssize_t *sum);

// _d_i_u_x_X.c
int					_d_i(va_list *ap, char **line, ssize_t *sum);
int					_u(va_list *ap, char **line, ssize_t *sum);
int					_lower_x(va_list *ap, char **line, ssize_t *sum);
int					_upper_x(va_list *ap, char **line, ssize_t *sum);
int					_p(va_list *ap, char **line, ssize_t *sum);

// ft_putnbr.c
int					ft_putnbr_d_i(char **line, long long n, ssize_t *sum);
int					ft_putnbr_u(char **line, unsigned long long n,
						ssize_t *sum);
int					ft_putnbr_x(char **line, unsigned long long n, ssize_t *sum,
						char flag);
char				set_c_x(unsigned long long n, char flag);

// get_next_line
typedef struct s_manage
{
	int				fd;
	char			*buf;
	struct s_manage	*next;
}					t_manage;

char				*get_next_line(int fd);
char				*loop(int fd, char *buf);

// list function
t_manage			*lstnewadd(t_manage **lst, int fd);
t_manage			*find_file(t_manage **lst, int fd);
ssize_t				del_file(t_manage **lst, int fd);

char				*ft_strjoin_lf(char *s1, char *s2);
void				_cp(char **res, char *s1, char *s2);
int					remain_right(char *buf);
size_t				ft_strlen_lf(const char *s);

// push_swap
typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_stacknew(int num);
size_t				ft_stacksize(t_stack *stack);
void				ft_stack_add(t_stack **stack, t_stack *new);
int					ft_stackpush(t_stack **stack, int num);
void				ft_stackswap(t_stack **stack);
int					ft_stackpop(t_stack **stack);
void				ft_stackclear(t_stack **stack);

#endif
