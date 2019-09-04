#ifndef UTILS__H
# define UTILS__H
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strdup(const char *s1);
// size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);

#endif