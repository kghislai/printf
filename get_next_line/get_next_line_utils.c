/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghislai <kghislai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 09:34:16 by kghislai          #+#    #+#             */
/*   Updated: 2020/07/01 09:35:57 by kghislai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
