/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmalman <ahmalman@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:45:18 by ahmalman          #+#    #+#             */
/*   Updated: 2023/06/07 20:54:24 by ahmalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_strlen(char* str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int ft_putstr_fd(char *str)
{
	int a = ft_strlen(str);
	write(1, str, a);
	return(a);
}

int	ft_putchar_fd(char c)
{
	write(1, &c, 1);
	return(1);
}

int	ft_putnbr_fd(int n)
{
	int	bl;
	
	bl = 0;
	if (n == -2147483648)
	{
		bl = bl + ft_putstr_fd("-2147483648");
	}
	else if (n < 0)
	{
		bl = bl + ft_putchar_fd('-');
		n = -n;
		ft_putnbr_fd(n);
	}
	else if (n > 9)
	{
		bl = bl + ft_putnbr_fd(n / 10);
		bl = bl + ft_putnbr_fd(n % 10);
	}
	else
	{
	bl = bl + ft_putchar_fd(n + 48);
	}
	return (bl);
}


int	ft_printf(char *str, ...)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	va_list	ptr;
	
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		 {
			i++;
			// x = x + ft_rest_printf(str[i], ptr);
			if (str[i] == 'c')
				x = x + ft_putchar_fd(va_arg(ptr, int));
			else if (str[i] == 's')
				x = x + ft_putstr_fd(va_arg(ptr, char *));
			else if (str[i] == 'd' || str[i] == 'i')
				x = x + ft_putnbr_fd(va_arg(ptr , int));
		 }
		else
			x = x + ft_putchar_fd(str[i]);
		i++;
	}
	va_end(ptr);
	return(x);
}


int main (void)
{
	int a;
	char *s;
	char b;
	
	a = -5;
	b = 'c';
	s = "yujgt";


	// int num = printf("[%d]  [%c]\n",a, b);
	ft_printf("%c %d %s\n", b, a ,s);

	// ft_printf();
}