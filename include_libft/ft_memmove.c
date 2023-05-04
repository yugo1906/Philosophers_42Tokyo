/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:00:25 by yughoshi          #+#    #+#             */
/*   Updated: 2022/10/20 15:38:57 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*up_dst;
	const unsigned char	*up_src;
	size_t				i;

	up_dst = (unsigned char *)dst;
	up_src = (const unsigned char *)src;
	i = 0;
	if (up_dst == up_src)
		return (dst);
	if (up_dst > up_src)
	{
		while (len-- > 0)
		{
			up_dst[len] = up_src[len];
		}
	}
	else
	{
		while (len > i)
		{
			up_dst[i] = up_src[i];
			i++;
		}
	}
	return (dst);
}
