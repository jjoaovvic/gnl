#include "get_next_line.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*pointer;

	if (((nitems * size) / size != nitems && size != 0))
		return (NULL);
	pointer = (void *)malloc(nitems * size);
	if (!pointer)
		return (NULL);
	while (nitems * size--)
		((unsigned char *)pointer)[nitems * size] = '\0';
	return (pointer);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len_total;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = -1;
	len_s2 = 0;
	if (!s1 || !s2)
		return (NULL);
	len_total = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	new_str = malloc (len_total);
	if (!new_str)
		return (NULL);
	while (s1[++len_s1])
		new_str[len_s1] = s1[len_s1];
	while (s2[len_s2])
		new_str[len_s1++] = s2[len_s2++];
	new_str[len_s1] = '\0';
	return (new_str);
}

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		size;
	int		i;

	size = ft_strlen(src);
	i = 0;
	copy = (char *)malloc ((size + 1) * sizeof(char));
	while (i <= size)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (start > ft_strlen(s))
	{
		substring = ft_calloc(1, sizeof(char));
		substring[0] = '\0';
		return (substring);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substring = ft_calloc(len + 1, sizeof(char));
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}
