/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:06:04 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/12/20 15:09:44 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(int *ret, int c)
{
	write(1, &c, 1);
	*ret += 1;
}

static void	ft_str(int *ret, char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*ret += 6;
		return ;
	}
	while (str[i])
	{
		ft_putchar(ret, str[i]);
		i++;
	}
}

int	ft_printf(const char *str, ...)
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
			if (str[i] == 's')
				ft_str(&ret, va_arg(arg, char *));
			else if (str[i] == 'c')
				ft_putchar(&ret, va_arg(arg, int));
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
