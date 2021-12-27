/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 10:10:05 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/12/27 13:24:51 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hexa(unsigned int nb, int *len)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_put_hexa((nb / 16), len);
		ft_put_hexa((nb % 16), len);
	}
	else if (nb <= 16)
		ft_putchar(base[nb], len);
}

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
		ft_putstr("(null)", len);
	else
	{
		while (str[i])
			ft_putchar(str[i++], len);
	}
}

void	ft_putptr(unsigned long ptr, int *len)
{
	ft_putstr("0x", len);
	ft_puthexa(ptr, len);
}

void	ft_putuns(unsigned int n, int *len)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = -n;
		ft_putchar('-', len);
	}
	else
		nb = n;
	if (nb > 9)
		ft_putuns(nb / 10, len);
	ft_putchar(nb % 10 + '0', len);
}
