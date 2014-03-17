/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:42:22 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/20 10:44:20 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 32
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define NNB(x)	x >= 0 ? x : -x

size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dest, const char *src);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	ft_putnbr(int n);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_strdel(char **as);
void	ft_putendl(char const *s);
void	ft_strclr(char *s);
void	ft_memdel(void **as);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
char	*ft_strncpy(char *dest, const char *src, size_t n);
int		ft_atoi(const char *nptr);
int		ft_isascii(int c);
int		ft_isprint(int c);
char	*ft_strstr(const char *src1, const char *src2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strcat(char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_strequ(char const *s1, char const *s2);
void	*ft_memalloc(size_t size);
char	*ft_strtrim(char const *s);
char	*ft_strnew(size_t size);
void	ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strsub(const char *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
char	**ft_strsplit(char const *s, char c);
int		get_next_line(int const fd, char **line);

typedef unsigned char uchar;

#endif
