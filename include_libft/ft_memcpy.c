/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:17:57 by yughoshi          #+#    #+#             */
/*   Updated: 2022/10/20 15:38:52 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*uc_dst;
	const unsigned char	*uc_src;
	size_t				i;

	uc_dst = (unsigned char *)dst;
	uc_src = (const unsigned char *)src;
	i = 0;
	if (uc_dst == uc_src)
	{
		return (dst);
	}
	while (n > i)
	{
		uc_dst[i] = uc_src[i];
		i++;
	}
	return (dst);
}
