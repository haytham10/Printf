/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:46:23 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/12/21 20:30:42 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_print	*ft_tab(t_print *tab)
{
	va_list args;
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->sign = 0;
	tab->tl = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->prec = 0;
	tab->sp = 0;
	tab->pnt = 0;
	return (tab);
}

int	ft_eval(t_print tab, const char format, int i)
{
	while (format[i] != 'u' || format[i] != 'd' || format[i] != 'c' || format[i] != 's'
			|| format[i] != 'p' || format[i] != 'x' || format[i] != 'X')
		{
			if (format[i++] == '.')
				tab->pnt = 1;
			else if (format[i++] == '-')
				tab->dash = 1;
			else if (format[i++] == ' ')
				tab->sp = 1;
			else if (format[i++] == '0')
				tab->is_zero = 1;
		}
		return (1);
}

int	ft_eval2()
{
	while (ft_eval == 1)
	{
		if (format[i] == 'c')
			ft_printchar(tab);
		else if (format[i] == 'd' || format[i] == 'i')
			ft_printnb(tab);
		else if (format[i] == 'x')
			ft_printhexa(tab);
		else if (format[i] == 'X')
			ft_printhexaa(tab);
		else if (format[i] == 'u')
			ft_printdec(tab);
		else if (format[i] == 'p')
			ft_printptr(tab);
		else if (format[i] == 's')
			ft_printstr(tab);
	}
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		ret;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_tab(tab);
	va_start(tab->args, format);
	i = -1;
	ret = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_eval(tab, format, i + 1);
		else
			ret += write(1, &format[i], 1);
	}
	va_end(tab->args);
	ret += tab->tl;
	free (tab);
	return (ret);
}