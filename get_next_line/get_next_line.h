/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghislai <kghislai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 09:28:34 by kghislai          #+#    #+#             */
/*   Updated: 2020/07/01 09:43:45 by kghislai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>


int         ft_strlen(const char *s);
char        *ft_strdup(const char *s);
char        *ft_strjoin(char const *s1, char const *s2);
char        *ft_strchr(const char *s, int c);
int         ft_strcpy(char *dest, const char *src);
int         get_next_line(int fd, char **line);
#endif