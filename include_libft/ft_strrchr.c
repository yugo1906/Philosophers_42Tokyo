/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:22:05 by yughoshi          #+#    #+#             */
/*   Updated: 2022/10/20 15:40:07 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_size;

	s_size = ft_strlen(s);
	if (c == 0)
		return ((char *)s + s_size);
	while (s_size--)
	{
		if (s[s_size] == (char)c)
		{
			return ((char *)&s[s_size]);
		}
	}
	return (NULL);
}
