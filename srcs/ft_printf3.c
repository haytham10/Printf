/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:27:02 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/12/20 15:32:50 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf3.h"
#include <stdio.h>

static void	ft_putchar(int *ret, char c)
{
	write(1, &c, 1);
	*ret += 1;
}

static void	ft_hexa(int *ret, unsigned int nb)
{
	char	base[16];

	base[16] = "0123456789abcdef";
	if (nb > 15)
	{
		ft_hexa(ret, nb / 16);
		ft_hexa(ret, nb % 16);
	}
	if (nb <= 15)
		ft_putchar(ret, base[nb]);
}

static void	put_ptr(uintptr_t nb)
{
	if (nb > 16)
	{
		put_ptr(nb / 16);
		put_ptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
			ft_putchar_fd((nb - 10 + 'a'), 1);
	}
}

static int	put_len(uintptr_t nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16; 
	}
	return (len);
}

static int	ft_ptr(int *ret, unsigned long long ptr)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	if (ptr == 0)
		i += write(1, "0", 1);
	else
	{
		put_ptr(ptr);
		i += put_len(ptr);
	}
	return (i);
}

int	ft_printf3(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	arg;

	i = 0;
	ret = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'x')
				ft_hexa(&ret, va_arg(arg, unsigned int));
			else if (str[i] == 'p')
				ft_ptr(&ret, va_arg(arg, unsigned long long));
		}
		else
			ft_putchar(&ret, str[i]);
		i++;
	}
	va_end(arg);
	return (ret);
}

int main()
{
	int i;

	ft_printf3("%p\n", &i);
}