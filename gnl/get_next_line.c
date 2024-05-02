#include "get_next_line.h"

static char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}

static char	*ft_take_line(char *save)
{
	int		i;
	char	*this_line;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	this_line = ft_substr(save, 0, i + 1);
	return (this_line);
}

static char	*ft_get_line(int fd, char *save)
{
	int		size;
	char	*temp;
	char	*buf;

	size = 1;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (size > 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			break ;
		buf[size] = '\0';
		if (!save)
			save = ft_strdup("");
		temp = save;
		save = ft_strjoin(temp, buf);
		free (temp);
		temp = NULL;
		if (ft_strchr(save, '\n'))
			break ;
	}
	free(buf);
	buf = NULL;
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*temp;
	char		*this_line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_get_line(fd, save);
	if (!save)
		return (NULL);
	else if (!*save)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	this_line = ft_take_line(save);
	temp = save;
	save = ft_substr(save, ft_strlen(this_line), ft_strlen(save));
	free(temp);
	temp = NULL;
	return (this_line);
}
