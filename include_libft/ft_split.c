/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:30:11 by yughoshi          #+#    #+#             */
/*   Updated: 2022/10/20 15:39:21 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	array_size_count(char const *str, char c)
{
	size_t	array_size;
	size_t	i;

	i = 0;
	array_size = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != c && str[i] != '\0')
		{
			while (str[i] != c && str[i] != '\0')
				i++;
			array_size++;
		}
	}
	return (array_size);
}

static char	*str_change_start_point(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	s = s + i;
	return (s);
}

static char	**ft_free(char **res)
{
	size_t	i;

	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	array_size;

	if (s == NULL)
		return (NULL);
	array_size = array_size_count(s, c);
	res = (char **)malloc(sizeof(char *) * (array_size + 1));
	if (res == NULL)
		return (NULL);
	j = 0;
	while (j < array_size)
	{
		i = 0;
		s = str_change_start_point((char *)s, c);
		while (((char *)s)[i] != '\0' && ((char *)s)[i] != c)
			i++;
		res[j] = ft_substr(s, 0, i);
		if (res[j++] == NULL)
			return (ft_free(res));
		s = s + i;
	}
	res[j] = NULL;
	return (res);
}
