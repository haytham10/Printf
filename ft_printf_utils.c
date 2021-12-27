/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 23:09:58 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/12/26 10:31:31 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

static unsigned int	ft_va(int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

void	ft_putnbr(int n)
{
	unsigned int	num;

	if (n < 0)
		ft_putchar('-');
	num = ft_va(n);
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + '0');
}

void	ft_puthexa(unsigned int nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb > 15)
	{
		ft_puthexa(nb / 16);
		ft_puthexa(nb % 16);
	}
	if (nb <= 16)
		ft_putchar(base[nb]);
}
