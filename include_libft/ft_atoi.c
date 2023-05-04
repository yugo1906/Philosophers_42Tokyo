/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:47:34 by yughoshi          #+#    #+#             */
/*   Updated: 2022/10/20 15:38:01 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;
	size_t		i;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (sign == 1 && (res > ((LONG_MAX - (sign * (str[i] - '0'))) / 10)))
			return ((int)LONG_MAX);
		if (sign == -1 && (res < ((LONG_MIN - (sign * (str[i] - '0'))) / 10)))
			return ((int)LONG_MIN);
		res = (res * 10) + (sign * (str[i] - '0'));
		i++;
	}
	return ((int)res);
}
