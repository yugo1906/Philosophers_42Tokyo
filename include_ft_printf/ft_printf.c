/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:17:52 by yughoshi          #+#    #+#             */
/*   Updated: 2022/10/25 12:34:42 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_fmt(va_list *ap, const char *fmt, int *len, char *s_ap)
{
	if (*fmt == '%')
		my_putchar_and_increment('%', 1, len);
	else if (*fmt == 'c')
		my_putchar_and_increment(va_arg(*ap, int), 1, len);
	else if (*fmt == 's')
	{
		s_ap = va_arg(*ap, char *);
		if (!s_ap)
			my_putstr_and_increment("(null)", 1, len);
		else
			my_putstr_and_increment(s_ap, 1, len);
	}
	else if (*fmt == 'd' || *fmt == 'i')
		my_putnbr_and_increment(va_arg(*ap, int), 1, len);
	else if (*fmt == 'u')
		my_putnbr_and_increment(va_arg(*ap, unsigned int), 1, len);
	else if (*fmt == 'x')
		put_base16(va_arg(*ap, unsigned int), "0123456789abcdef", len);
	else if (*fmt == 'X')
		put_base16(va_arg(*ap, unsigned int), "0123456789ABCDEF", len);
	else if (*fmt == 'p')
	{
		my_putstr_and_increment("0x", 1, len);
		put_address(va_arg(*ap, unsigned long long), "0123456789abcdef", len);
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		res_len;
	char	*fmt_s_ap;

	va_start(ap, fmt);
	res_len = 0;
	fmt_s_ap = NULL;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			print_fmt(&ap, fmt, &res_len, fmt_s_ap);
		}
		else
		{
			my_putchar_and_increment(*fmt, 1, &res_len);
		}
		fmt++;
	}
	va_end(ap);
	return (res_len);
}

/*
#include <stdio.h>

int	main(void)
{
	char	a;
	int		b;
	int		c;
	int		x;
	int		y;

	a = 'a';
	// ptr_a = &a;
	// • %d: 10 進数 (基数 10) を出力します。
	printf("%s\n%s\n", "---", "%d: 10 進数 (基数 10) を出力");
	printf("%daaa\n", 1);
	ft_printf("%daaa\n", 1);
	// ---
	// %c: 一文字を出力
	printf("%s\n%s\n", "---", "%c: 一文字を出力");
	printf("%c%c\n", 'a', 'x');
	ft_printf("%c%c\n", 'a', 'x');
	printf("%c a\n", '\0');
	ft_printf("%c a\n", '\0');
	// ---
	// %s: 文字列を出力
	printf("%s\n%s\n", "---", "%s: 文字列を出力");
	x = printf("%s aasdfsf%s\n", "Hello 42", "Hello 42");
	y = ft_printf("%s aasdfsf%s\n", "Hello 42", "Hello 42");
	printf("%d\n%d\n", x, y);
	// 可変長引数に0(≒null)がある時のテスト
	// b = printf("%s\n", 0);
	// c = ft_printf("%s\n", 0);
	// printf("%d, %d\n", b, c);
	// ---
	// %p: void *ポインター引数は、16 進形式で出力する必要があります
	printf("%s\n%s\n", "---", "%p: void *ポインター引数を、16進数形式で出力");
	printf("%p\n", &a);
	ft_printf("%p\n", &a);
	// ---
	// %i 基数 10 の整数を出力します。
	printf("%s\n%s\n", "---", "%i: 基数 10 の整数を出力");
	printf("%i\n", 10);
	ft_printf("%i\n", 10);
	// ---
	// %u: 符号なし 10 進数 (基数 10) を出力します。
	printf("%s\n%s\n", "---", "%u: 符号なし 10 進数 (基数 10) を出力");
	printf("%u\n", -123);
	ft_printf("%u\n", -123);
	// ---
	// %x 数値を 16 進数 (基数 16) の小文字形式で出力します。
	printf("%s\n%s\n", "---", "%x: 数値を 16 進数 (基数 16) の小文字形式で出力");
	printf("%x\n", 2500);
	ft_printf("%x\n", 2500);
	// ---
	// • %X 数値を 16 進数 (基数 16) の大文字形式で出力します。
	printf("%s\n%s\n", "---", "%X: 数値を 16 進数 (基数 16) の大文字形式で出力");
	printf("%X\n", 2500);
	ft_printf("%X\n", 2500);
	// ---
	// • %% パーセント記号を出力します。
	printf("%s\n%s\n", "---", "%%: パーセント記号を出力");
	printf("%%\n");
	ft_printf("%%\n");
	return (0);
}
*/
