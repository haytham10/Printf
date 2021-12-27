/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 09:39:09 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/12/27 12:55:03 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(const char *str, va_list arg, int i, int *len)
{
	if (str[i] == 's')
		ft_putstr(va_arg(arg, char *), len);
	else if (str[i] == 'c')
		ft_putchar(va_arg(arg, int), len);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr(va_arg(arg, int), len);
	else if (str[i] == 'x')
		ft_puthexa(va_arg(arg, unsigned int), len);
	else if (str[i] == 'X')
		ft_put_hexa(va_arg(arg, unsigned int), len);
	else if (str[i] == 'p')
		ft_putptr(va_arg(arg, unsigned long), len);
	else if (str[i] == 'u')
		ft_putuns(va_arg(arg, unsigned int), len);
	else if (str[i] == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_print(str, arg, i, &len);
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(arg);
	return (len);
}
