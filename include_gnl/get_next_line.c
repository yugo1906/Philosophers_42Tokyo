/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 07:10:41 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/04 18:07:06 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

char	*get_buf(int fd, char *st_buf)
{
	char	*tmp;
	ssize_t	read_bytes;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (tmp == NULL)
		return (NULL);
	read_bytes = 1;
	while (ft_strchr_gnl(st_buf, '\n') == NULL)
	{
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		tmp[read_bytes] = '\0';
		st_buf = ft_strjoin_gnl(st_buf, tmp);
		if (st_buf == NULL)
		{
			free(tmp);
			return (NULL);
		}
	}
	free(tmp);
	if (read_bytes == -1)
		return (NULL);
	return (st_buf);
}

char	*get_one_line(char *st_buf)
{
	char	*res_one_line;
	size_t	i;

	i = 0;
	if (st_buf[i] == '\0')
		return (NULL);
	res_one_line = malloc(sizeof(char) * (ft_strlen_gnl(st_buf) + 1));
	if (res_one_line == NULL)
		return (NULL);
	while (st_buf[i] != '\n' && st_buf[i] != '\0')
	{
		res_one_line[i] = st_buf[i];
		i++;
	}
	if (st_buf[i] == '\n')
		res_one_line[i++] = '\n';
	res_one_line[i] = '\0';
	return (res_one_line);
}

char	*get_next_start_point(char *st_buf)
{
	char	*res_next_start_point;
	size_t	i;
	size_t	j;

	i = 0;
	while (st_buf[i] != '\n' && (st_buf[i] != '\0'))
		i++;
	if (st_buf[i] == '\0')
	{
		free(st_buf);
		return (NULL);
	}
	res_next_start_point = malloc(sizeof(char) * ft_strlen_gnl(st_buf) + 1);
	if (res_next_start_point == NULL)
		return (NULL);
	i++;
	j = 0;
	while (st_buf[i + j] != '\0')
	{
		res_next_start_point[j] = st_buf[i + j];
		j++;
	}
	res_next_start_point[j] = '\0';
	free(st_buf);
	return (res_next_start_point);
}

char	*get_next_line(int fd)
{
	char		*res_line;
	static char	*st_buf;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	st_buf = get_buf(fd, st_buf);
	if (st_buf == NULL)
		return (NULL);
	res_line = get_one_line(st_buf);
	st_buf = get_next_start_point(st_buf);
	return (res_line);
}
