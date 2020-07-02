

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int	ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	if (src == NULL)
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
char	*ft_strchr(const char *s, int c)
{
	char symb;

	symb = (char)c;
	while (*s != '\0')
	{
		if (*s == symb)
			return ((char *)s);
		s++;
	}
	if (*s == symb)
		return ((char *)s);
	return (NULL);
}
int			ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
char		*ft_strdup(const char *s)
{
	char	*d;
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	d = malloc(i * sizeof(char) + 1);
	if (d == 0)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == 0)
		return (NULL);
	while (*s1 != '\0')
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}



int		ft_return(char **tail, char *ptr,  int limit)
{
	if (limit > 0 || ptr != NULL)
		return (1);
	else
	{
		if(*tail)
		{
			free(*tail);
			*tail = NULL;
		}
		return (0);
	}
}
char *ft_tail(char *tail, char **line)
{
    char *ptr;

    ptr = NULL;
    if(tail)
    {
        if ((ptr = ft_strchr(tail, '\n')))
        {
            *ptr = '\0';
            *line = ft_strdup(tail);
            ft_strcpy(tail, ++ptr);
        }
        else 
        {
            *line = ft_strdup(tail);
        }
    }
    else
        *line = ft_strdup("");
    return(ptr);
}
void ft_clear(char **line, char *buf)
{
	char *clear;

	clear = *line;
    *line = ft_strjoin(*line, buf);
    free(clear);
}
int		ft_minusone(char **buf, int fd)
{
	if ((*buf = (char*)malloc(BUFFER_SIZE + 1)) == NULL)
		return (1);
	if(fd < 0)
		return (1);
	if ((read(fd, *buf, 0)) == -1)
	{
		free(*buf);
		return (1);
	}
	return (0);
}
int get_next_line(int fd, char **line)
{
    char *buf;
    int limit;
    char *ptr;
    static char *tail;

	if (ft_minusone(&buf, fd))
		return (-1);
    ptr = ft_tail(tail, line);
    while(ptr == NULL && (limit = read(fd, buf, BUFFER_SIZE)))
    {
        buf[limit] = '\0';
        
        if((ptr = ft_strchr(buf, '\n')))
        {
            *ptr = '\0';
            if (tail)
                free(tail);
            tail = ft_strdup(++ptr);
        }
        ft_clear(line, buf);
    }
    return (ft_return(&tail, ptr, limit));
}
int main()
{
    int fd = open("./test2.txt", O_RDONLY);
    char *line;
    int i = 1;
    int s;
    while ((s = get_next_line(fd, &line)) > 0 )
    {
        printf("%d: %s\n",i, line);
        i++;
        free(line);
    }
	printf("%d: %s\n",i, line);
    //printf("%d:\n", i);
    free(line);
    return 0;
}