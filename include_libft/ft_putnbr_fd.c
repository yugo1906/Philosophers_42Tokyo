/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:44:40 by yughoshi          #+#    #+#             */
/*   Updated: 2022/10/20 15:39:13 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	long_n;

	long_n = n;
	if (long_n < 0)
	{
		ft_putchar_fd('-', fd);
		long_n *= -1;
	}
	if (long_n < 10)
		ft_putchar_fd(long_n + '0', fd);
	else
	{
		ft_putnbr_fd(long_n / 10, fd);
		ft_putnbr_fd(long_n % 10, fd);
	}
}
