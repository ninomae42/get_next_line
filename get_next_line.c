#include "get_next_line.h"

// create a line from the string passed by an argument.
char	*create_line(const char *save)
{
	char	*p_line;
	size_t	i;

	i = 0;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	p_line = (char *)malloc(sizeof(char) * (i + 1 + 1));
	if (p_line == NULL)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		p_line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		p_line[i] = save[i];
		i++;
	}
	p_line[i] = '\0';
	return (p_line);
}

// read from fd to buffer, and save it to static variable 'save'.
char	*read_from_fd_and_save(int fd, char *save)
{
	char	*buf;
	char	*p_save_free;
	ssize_t	bytes_read;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	bytes_read = 1;
	while (ft_strchr_s(save, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		p_save_free = save;
		save = ft_strjoin(save, buf);
		free(p_save_free);
		p_save_free = NULL;
	}
	free(buf);
	return (save);
}

// trim the line that is in variable 'line' and creates copy of save
char	*trim_line_in_save(char *save)
{
	char	*p_ret;
	size_t	i;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	p_ret = (char *)malloc(sizeof(char) * (ft_strlen_s(save) - i + 1));
	if (p_ret == NULL)
		return (NULL);
	i++;
	ft_stpcpy_s(p_ret, &save[i]);
	free(save);
	return (p_ret);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_from_fd_and_save(fd, save);
	if (save == NULL)
		return (NULL);
	line = create_line(save);
	save = trim_line_in_save(save);
	return (line);
}
