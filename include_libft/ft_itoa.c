/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:50:47 by yughoshi          #+#    #+#             */
/*   Updated: 2022/10/20 15:38:27 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digit(long long num)
{
	size_t	digit;

	digit = 1;
	if (num < 0)
	{
		num *= -1;
		digit++;
	}
	while (num >= 10)
	{
		num = num / 10;
		digit++;
	}
	return (digit);
}

static long	minus_to_plus(long long num, char *res, size_t *sign)
{
	res[0] = '-';
	num = num * -1;
	*sign = 1;
	return (num);
}

static char	*str_generation(long long num, char *res, size_t sign, size_t len)
{
	while (len > 0)
	{
		res[len] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	if (sign == 0)
		res[0] = num % 10 + '0';
	return (res);
}

char	*ft_itoa(int n)
{
	char		*res;
	long long	long_n;
	size_t		sign;
	size_t		len_n;

	long_n = n;
	sign = 0;
	len_n = get_digit(long_n);
	res = (char *)malloc(sizeof(char) * (len_n + 1));
	if (res == NULL)
		return (NULL);
	if (n < 0)
		long_n = minus_to_plus(n, res, &sign);
	res[len_n] = '\0';
	res = str_generation(long_n, res, sign, len_n - 1);
	return (res);
}
