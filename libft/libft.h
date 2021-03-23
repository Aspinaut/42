/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:01:20 by vmasse            #+#    #+#             */
/*   Updated: 2020/11/18 09:57:56 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
// ATTENTION SUPPRIMER CE COM + LES 3 INCLUDES QUI SUIVENT
# include <stddef.h>
# include <stdio.h>

// char  *ft_itoa(int n);
// char  **ft_strsplit(char const *s, char c);
// size_t  ft_strlcpy(char *dst, const char *src, size_t size);

size_t  ft_strlcat(char *dst, const char *src, size_t size);
void  *ft_calloc(size_t nmemb, size_t size);
int  ft_memcmp(const void *s1, const void *s2, size_t n);
void  *ft_memchr(const void *s, int c, size_t n);
void  *ft_memmove(void *dest, const void *src, size_t n);
void  ft_putnbr_fd(int n, int fd);
void  ft_putendl_fd(char const *s, int fd);
void  ft_putstr_fd(char const *s, int fd);
void  ft_putchar_fd(char c, int fd);
void  ft_putendl(char const *s);
void	ft_putstr(char const *s);
char  *ft_strtrim(char const *s1, char const *set);
char  *ft_substr(char const *s, unsigned int start, size_t len);
int  ft_strnequ(char const *s1, char const *s2, size_t n);
int  ft_strequ(char const *s1, char const *s2);
char  *ft_strmapi(char const *s, char (*f)(unsigned int, char));
char  *ft_strmap(char const *s, char (*f)(char));
void  ft_striteri(char *s, void (*f)(unsigned int, char *));
void  ft_striter(char *s, void (*f)(char *));
void  ft_strclr(char *s);
void  ft_strdel(char **as);
char  *ft_strnew(size_t size);
void  ft_memdel(void **ap);
void  *ft_memalloc(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putnbr(int n);
void	ft_putchar(char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int	ft_toupper(int c);
int	ft_tolower(int c);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int	ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
int	ft_strlen(char *str);
char	*ft_strdup(char *src);
int	ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
int	ft_isprint(int c);
int	ft_isdigit(int c);
int	ft_isascii(int c);
int	ft_isalpha(int c);
int	ft_isalnum(int c);
void	ft_bzero(void *s, size_t n);
int	ft_atoi(char *str);

char  *ft_strtrim_spaces(char const *s);

#endif
