/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:32:01 by yughoshi          #+#    #+#             */
/*   Updated: 2022/10/20 15:40:15 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*res;

	if (s == NULL)
	{
		return (NULL);
	}
	len_s = ft_strlen(s);
	if (len <= 0 || len_s <= start)
	{
		return (ft_strdup(""));
	}
	if (len > len_s - start)
	{
		len = len_s - start;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(res, &s[start], len + 1);
	return (res);
}
