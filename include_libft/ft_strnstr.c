/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:31:50 by yughoshi          #+#    #+#             */
/*   Updated: 2022/10/20 15:40:03 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] != '\0')
	{
		j = 0;
		while ((big[i + j] == little[j] || little[j] == '\0') && (i + j) <= len)
		{
			if (little[j] == '\0')
				return (((char *)big) + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
