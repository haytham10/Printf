/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 10:10:05 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/12/26 10:31:39 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hexa(unsigned int nb)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nb > 15)
	{
		ft_put_hexa(nb / 16);
		ft_put_hexa(nb % 16);
	}
	if (nb <= 16)
		ft_putchar(base[nb]);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
		ft_puthexa(ptr);
}

static unsigned int	ft_va(int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

void	ft_putuns(unsigned int n)
{
	unsigned int	num;

	if (n < 0)
		ft_putchar('-');
	num = ft_va(n);
	if (num >= 10)
	{
		ft_putuns(num / 10);
		ft_putuns(num % 10);
	}
	else
		ft_putchar(num + '0');
}
