/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghislai <kghislai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:02:38 by kghislai          #+#    #+#             */
/*   Updated: 2020/07/01 09:43:43 by kghislai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
