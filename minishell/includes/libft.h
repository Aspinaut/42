#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define	MAX_LONG	9223372036854775807

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
int		ft_strchr_pos(char *s, char c, int pos);
int		is_space(char c);
int		is_chevron(char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_isalnum(int c);

#endif
