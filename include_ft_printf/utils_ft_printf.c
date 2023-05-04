/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:22:32 by yughoshi          #+#    #+#             */
/*   Updated: 2022/10/25 11:54:41 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	my_putchar_and_increment(char c, int fd, int *res_len)
{
	write(fd, &c, 1);
	*res_len = *res_len + 1;
}

void	put_address(unsigned long long n, char *base_16, int *res_len)
{
	unsigned long long	base_16_digit;

	base_16_digit = 16;
	if (n < base_16_digit)
		my_putchar_and_increment(base_16[n], 1, res_len);
	else
	{
		put_address(n / base_16_digit, base_16, res_len);
		put_address(n % base_16_digit, base_16, res_len);
	}
}

void	put_base16(long long n, char *base_16, int *res_len)
{
	long long	base_16_digit;

	base_16_digit = 16;
	if (n < base_16_digit)
		my_putchar_and_increment(base_16[n], 1, res_len);
	else
	{
		put_base16(n / base_16_digit, base_16, res_len);
		put_base16(n % base_16_digit, base_16, res_len);
	}
}

void	my_putnbr_and_increment(long long n, int fd, int *res_len)
{
	long long	long_n;

	long_n = n;
	if (long_n < 0)
	{
		my_putchar_and_increment('-', fd, res_len);
		long_n *= -1;
	}
	if (long_n < 10)
		my_putchar_and_increment(long_n + '0', fd, res_len);
	else
	{
		my_putnbr_and_increment(long_n / 10, fd, res_len);
		my_putnbr_and_increment(long_n % 10, fd, res_len);
	}
}

void	my_putstr_and_increment(char *s, int fd, int *res_len)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		my_putchar_and_increment(s[i], fd, res_len);
		i++;
	}
}
