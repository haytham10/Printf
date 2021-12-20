/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:10:29 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/12/20 12:53:11 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf2.h"
#include "ft_printf3.h"

static void	ft_putchar(int *ret, char c)
{
	write(1, &c, 1);
	*ret += 1;
}

static void	ft_nb(int *ret, int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		*ret += 11;
		return ;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		*ret += 1;
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_nb(ret, nb / 10);
		ft_nb(ret, nb % 10);
	}
	else if (nb <= 9)
		ft_putchar(ret, nb + 48);
}

int	ft_printf2(char *str, ...)
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
			else if (str[i] == 'd')
				ft_nb(&ret, va_arg(arg, int));
			else
				ft_putchar(&ret, str[i]);
		}
		else
			ft_putchar(&ret, str[i]);
		i++;
	}
	va_end(arg);
	return (ret);
}
