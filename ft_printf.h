/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 10:23:20 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/12/26 10:46:57 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_print(const char *str, va_list arg, int i);
void	ft_putchar(int c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_puthexa(unsigned int nb);
void	ft_put_hexa(unsigned int nb);
void	ft_putptr(unsigned long long ptr);
void	ft_putuns(unsigned int n);

#endif
