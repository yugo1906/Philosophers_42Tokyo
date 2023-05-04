/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:02:33 by yughoshi          #+#    #+#             */
/*   Updated: 2022/10/20 15:39:30 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(ptr, s1, s1_len + 1);
	return (ptr);
}
