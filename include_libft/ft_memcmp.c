/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:35:04 by yughoshi          #+#    #+#             */
/*   Updated: 2022/10/20 15:38:47 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_uc;
	const unsigned char	*s2_uc;
	size_t				i;

	s1_uc = (const unsigned char *)s1;
	s2_uc = (const unsigned char *)s2;
	i = 0;
	while (n > i)
	{
		if (s1_uc[i] != s2_uc[i])
		{
			return ((int)(s1_uc[i] - s2_uc[i]));
		}
		i++;
	}
	return (0);
}
