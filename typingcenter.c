/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typingcenter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmalman <ahmalman@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:45:18 by ahmalman          #+#    #+#             */
/*   Updated: 2023/06/09 22:33:59 by ahmalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "ft_printf.h"

int	realprinter(char str, va_list ptr)
{
	int x;

	x = 0;
	if (str == 'c')
		x = x + ft_putchar(va_arg(ptr, int));
	else if (str == 's')
		x = x + ft_putstr(va_arg(ptr, char *));
	else if (str == 'd' || str == 'i')
		x = x + ft_putnbr(va_arg(ptr , int));
	else if (str == 'u')
		x = x + ft_putunbr(va_arg(ptr, unsigned int));
	else if (str == '%')
		x = x + ft_putchar('%');
	else if (str == 'x')
		x = x + smallhex(va_arg(ptr , unsigned int));
	else if (str == 'X')
		x = x + hugehex(va_arg(ptr , unsigned int));
	else if (str == 'p')
	{
		x = x + ft_putstr ("0x");
		x = x + nurmhex(va_arg(ptr , unsigned long));
	}
	return(x);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		x;
	va_list	ptr;

	i = 0;
	x = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
			x = x + realprinter(str[++i], ptr);
		else
			x = x + ft_putchar(str[i]);
		i++;
	}
	va_end(ptr);
	return(x);
}


// int main (void)
// {
// 	int a;
// 	char *s;
// 	char b;
	
// 	a = -5;
// 	b = 'c';
// 	s = "yujgt";
// 	int u = -2;

// 	ft_printf("%c %d %s %u %% %p\n", b, a ,s, u, 42069);
// 	printf("%c %d %s %u %% %p\n", b, a ,s, u, 42069);


// }