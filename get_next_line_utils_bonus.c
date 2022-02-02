#include "get_next_line_bonus.h"

// locate character in string. When s is NULL, return NULL.
char	*ft_strchr_s(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0' && (char)c == *s)
		return ((char *)s);
	return (NULL);
}

// find length of string. When s is NULL, return 0.
size_t	ft_strlen_s(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

// copy strings. It returns a pointer to the terminating '\0'.
// When dst or src is NULL, return NULL.
char	*ft_stpcpy_s(char *dst, const char *src)
{
	size_t	i;

	if (dst == NULL || src == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (&dst[i]);
}

// save a copy of a string. When s is NULL, return NULL.
char	*ft_strdup_s(const char *s)
{
	char	*p_ret;

	p_ret = (char *)malloc(sizeof(char) * (ft_strlen_s(s) + 1));
	if (p_ret == NULL)
		return (NULL);
	ft_stpcpy_s(p_ret, s);
	return (p_ret);
}

// Allocates and returns a new string, which is the result of
// the concatenation of 's1' and 's2'.
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*p_ret;
	size_t	alloc_size;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup_s(""));
	else if (s1 == NULL)
		return (ft_strdup_s(s2));
	else if (s2 == NULL)
		return (ft_strdup_s(s1));
	alloc_size = sizeof(char) * (ft_strlen_s(s1) + ft_strlen_s(s2) + 1);
	p_ret = (char *)malloc(alloc_size);
	if (p_ret == NULL)
		return (NULL);
	ft_stpcpy_s(ft_stpcpy_s(p_ret, s1), s2);
	return (p_ret);
}
