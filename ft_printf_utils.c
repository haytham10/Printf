/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 23:09:58 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/12/27 13:10:16 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *len)
{
	*len += write(1, &c, 1);
}

static unsigned int	ft_va(int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

void	ft_putnbr(int n, int *len)
{
	unsigned int	num;

	if (n < 0)
		ft_putchar('-', len);
	num = ft_va(n);
	if (num >= 10)
	{
		ft_putnbr((num / 10), len);
		ft_putnbr((num % 10), len);
	}
	else
		ft_putchar((num + '0'), len);
}

void	ft_puthexa(unsigned long nb, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_puthexa(nb / 16, len);
		ft_puthexa(nb % 16, len);
	}
	else
		ft_putchar(base[nb], len);
}
