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
	p_line = (char *)malloc(sizeof(char) * i);
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
		p_line[i] = '\n';
		i++;
	}
	if (save[i] == '\0')
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
	while (ft_strchr_s(buf, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE + 1);
		if (bytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		p_save_free = save;
		save = ft_strjoin(save, buf);
		free(p_save_free);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	save = read_from_fd_and_save(fd, save);
	if (save == NULL)
		return (NULL);
	line = create_line(save);
	return (line);
}
