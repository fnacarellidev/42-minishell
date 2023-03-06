/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:58:14 by fnacarel          #+#    #+#             */
/*   Updated: 2022/12/15 20:33:18 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen_printf(char *str)
{
	size_t	count;

	count = 0;
	if (str)
	{
		while (*str)
		{
			str++;
			count++;
		}
	}
	return (count);
}

int	ft_put_address(unsigned long long nbr)
{
	int	chars_printed;

	chars_printed = 0;
	if (!nbr)
	{
		chars_printed += ft_putstr_printf(NULLABLE);
		return (chars_printed);
	}
	chars_printed += ft_putstr_printf("0x");
	chars_printed += puthex_printf(nbr, 0);
	return (chars_printed);
}

int	puthex_printf(unsigned long long nbr, int use_uppercase)
{
	int		chars_printed;
	char	*base;

	chars_printed = 0;
	if (use_uppercase)
		base = HEX_UPCASE;
	else
		base = HEX_LWCASE;
	if (nbr < 16)
		chars_printed += putchar_printf(base[nbr]);
	else
	{
		chars_printed += puthex_printf(nbr / 16, use_uppercase);
		chars_printed += puthex_printf(nbr % 16, use_uppercase);
	}
	return (chars_printed);
}

int	put_base_printf(long long nbr, char *base)
{
	int	len_base;
	int	chars_printed;

	chars_printed = 0;
	len_base = ft_strlen_printf(base);
	if (nbr < 0)
	{
		nbr *= -1;
		chars_printed += putchar_printf('-');
	}
	if (nbr < len_base)
		chars_printed += putchar_printf(base[nbr]);
	else
	{
		chars_printed += put_base_printf(nbr / len_base, base);
		chars_printed += put_base_printf(nbr % len_base, base);
	}
	return (chars_printed);
}

int	ft_putstr_printf(char *str)
{
	int	chars_printed;

	chars_printed = 0;
	if (str)
	{
		while (str[chars_printed])
		{
			write(1, &str[chars_printed], 1);
			chars_printed++;
		}
	}
	else
		chars_printed += ft_putstr_printf("(null)");
	return (chars_printed);
}
