#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*read_from_fd_and_save(int fd, char *save);
char	*create_line(const char *save);
char	*trim_line_in_save(char *save);

size_t	ft_strlen_s(const char *s);
char	*ft_strchr_s(const char *s, int c);
char	*ft_strdup_s(const char *s);
char	*ft_stpcpy_s(char *dst, const char *src);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
