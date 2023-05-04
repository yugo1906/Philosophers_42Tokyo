/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:46:01 by yughoshi          #+#    #+#             */
/*   Updated: 2022/10/20 15:40:11 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start_point;
	size_t	end_point;
	size_t	len_s1;
	size_t	size;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	start_point = 0;
	end_point = len_s1;
	while (start_point < len_s1 && ft_strchr(set, s1[start_point]))
		start_point++;
	while (start_point < end_point && ft_strchr(set, s1[end_point - 1]))
		end_point--;
	size = end_point - start_point;
	res = ft_substr((char *)s1 + start_point, 0, size);
	return (res);
}
