/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmalman <ahmalman@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:57:51 by ahmalman          #+#    #+#             */
/*   Updated: 2023/06/12 19:42:58 by ahmalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	a;

	a = 0;
	if (!str)
	{
		a = ft_putstr("(null)");
		return (a);
	}
	a = ft_strlen(str);
	write(1, str, a);
	return (a);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putunbr(unsigned int u)
{	
	int	bl;

	bl = 0;
	if (u > 9)
	{
		bl = bl + ft_putunbr(u / 10);
		bl = bl + ft_putunbr(u % 10);
	}
	else
		bl = bl + ft_putchar(u + 48);
	return (bl);
}

int	ft_putnbr(int n)
{
	int	bl;

	bl = 0;
	if (n == -2147483648)
		bl = bl + ft_putstr("-2147483648");
	else if (n < 0)
	{
		bl = bl + ft_putchar('-');
		n = -n;
		bl = bl + ft_putnbr(n);
	}
	else if (n > 9)
	{
		bl = bl + ft_putnbr(n / 10);
		bl = bl + ft_putnbr(n % 10);
	}
	else
		bl = bl + ft_putchar(n + 48);
	return (bl);
}
