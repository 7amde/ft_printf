/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmalman <ahmalman@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:11:28 by ahmalman          #+#    #+#             */
/*   Updated: 2023/06/12 19:41:11 by ahmalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_strlen(char *str);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	smallhex(unsigned int h);
int	hugehex(unsigned int h);
int	nurmhex(unsigned long t);
int	ft_putunbr(unsigned int u);
int	ft_putnbr(int n);
int	ft_printf(const char *str, ...);

#endif