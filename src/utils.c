#include "so_long.h"

char	*join_and_free(char *tmp_line, char *buffer)
{
	char	*line;

	line = ft_strjoin(tmp_line, buffer);
	free(tmp_line);
	return (line);
}

char	*read_file(int fd, char *tmp_line)
{
	char	*buffer;
	int		bytes_read;

	if (!tmp_line)
		tmp_line = ft_calloc(1, 1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(tmp_line);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		tmp_line = join_and_free(tmp_line, buffer);
		if (ft_strchr(tmp_line, '\n'))
			break ;
	}
	free(buffer);
	return (tmp_line);
}

char	*ft_next(char *buffer)
{
	char	*bufbis;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	bufbis = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!bufbis)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i] != '\0')
		bufbis[j++] = buffer[i++];
	bufbis[j] = '\0';
	free(buffer);
	return (bufbis);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	while (i > j)
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}