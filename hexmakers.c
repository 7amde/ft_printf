/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexmakers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmalman <ahmalman@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:01:37 by ahmalman          #+#    #+#             */
/*   Updated: 2023/06/09 20:04:51 by ahmalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int smallhex(unsigned int h)
{
	int		i;
	int		x;
	char	*abcd;

	x = 0;
	abcd = "0123456789abcdef";
	if (h >15)
		x = x + smallhex (h / 16);
	i = h % 16;
	x = x + ft_putchar (abcd[i]);
	return(x);
}

int hugehex(unsigned int h)
{
	int		i;
	int		x;
	char	*abcd;

	x = 0;
	abcd = "0123456789ABCDEF";
	if (h >15)
		x = x + hugehex (h / 16);
	i = h % 16;
	x = x + ft_putchar (abcd[i]);
	return (x);
}

int nurmhex(unsigned long t)
{
	int		i;
	int		x;
	char	*abcd;

	x = 0;
	abcd = "0123456789abcdef";
	if (t >15)
		x = x + nurmhex (t / 16);
	i = t % 16;
	x = x + ft_putchar (abcd[i]);
	return (x);
}
