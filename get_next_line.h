#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
# endif

char *get_next_line(int fd);
size_t ft_strlen(const char   *s);
char	*ft_strchr(const char *str, int c);
char *ft_strdup(char const *src);
char *ft_outputline(char *save);
char *ft_leftover(char *save);
char *ft_read(int fd, char *save);
char    *ft_strjoin(char *s1, char *s2);
#endif