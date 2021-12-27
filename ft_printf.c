/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 09:39:09 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/12/27 10:16:56 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(const char *str, va_list arg, int i)
{
	if (str[i] == 's')
		ft_putstr(va_arg(arg, char *));
	else if (str[i] == 'c')
		ft_putchar(va_arg(arg, int));
	else if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr(va_arg(arg, int));
	else if (str[i] == 'x')
		ft_puthexa(va_arg(arg, unsigned int));
	else if (str[i] == 'X')
		ft_put_hexa(va_arg(arg, unsigned int));
	else if (str[i] == 'p')
		ft_putptr(va_arg(arg, unsigned long long));
	else if (str[i] == 'u')
		ft_putuns(va_arg(arg, unsigned int));
	else if (str[i] == '%')
		ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	int		res;
	int		i;
	va_list	arg;

	i = 0;
	res = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_print(str, arg, i);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (res);
}
