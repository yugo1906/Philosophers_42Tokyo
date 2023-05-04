/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:56:59 by yughoshi          #+#    #+#             */
/*   Updated: 2022/10/18 13:15:24 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*uc_s;
	unsigned char		uc_c;
	size_t				i;

	uc_s = (const unsigned char *)s;
	uc_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (uc_s[i] == uc_c)
		{
			return ((void *)uc_s + i);
		}
		i++;
	}
	return (NULL);
}
