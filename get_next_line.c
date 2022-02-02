#include "get_next_line.h"

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
	static char	*save;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	save = read_from_fd_and_save(fd, save);
	if (save == NULL)
		return (NULL);
	else
		return (save);
}
