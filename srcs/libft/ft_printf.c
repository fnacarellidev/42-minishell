/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:22:50 by fnacarel          #+#    #+#             */
/*   Updated: 2023/04/21 15:42:06 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	putchar_printf(int fd, char c)
{
	return (write(fd, &c, 1));
}

static int	ft_percent_handler(char c, va_list ptr, int fd)
{
	int	chars_printed;

	chars_printed = 0;
	if (c == 'c')
		chars_printed += putchar_printf(fd, va_arg(ptr, int));
	else if (c == 's')
		chars_printed += ft_putstr_printf(fd, va_arg(ptr, char *));
	else if (c == 'p')
		chars_printed += ft_put_address(fd, va_arg(ptr, unsigned long long));
	else if (c == 'd' || c == 'i')
		chars_printed += put_base_printf(fd, va_arg(ptr, int), DEC_DIGITS);
	else if (c == 'u')
		chars_printed += put_base_printf(fd, va_arg(ptr, unsigned int), DEC_DIGITS);
	else if (c == 'x')
		chars_printed += put_base_printf(fd, va_arg(ptr, unsigned int), HEX_LWCASE);
	else if (c == 'X')
		chars_printed += put_base_printf(fd, va_arg(ptr, unsigned int), HEX_UPCASE);
	else if (c == '%')
		return (write(fd, "%", 1));
	return (chars_printed);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	ptr;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(ptr, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_percent_handler(str[++i], ptr, fd);
		else
			count += putchar_printf(fd, str[i]);
		i++;
	}
	va_end(ptr);
	return (count);
}
