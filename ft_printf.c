/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:11:35 by ibaaziz           #+#    #+#             */
/*   Updated: 2024/11/23 13:18:20 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(char *str, va_list args)
{
	char	*base;

	base = "0123456789abcdef";
	if (str[1] == 'i' || str[1] == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1, 0));
	else if (str[1] == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (str[1] == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (str[1] == 'x')
		return (putnbr_base(va_arg(args, int), base));
	else if (str[1] == 'X')
		return (putnbr_base(va_arg(args, int), "0123456789ABCDEF"));
	else if (str[1] == 'p')
		return (putptr(va_arg(args, unsigned long int), base));
	else if (str[1] == 'u')
		return (ft_putnbr_fd(va_arg(args, int), 1, 1));
	else if (str[1] == '%')
		return (ft_putchar_fd('%', 1));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count = count + check_type((char *)&str[i], args);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/*
int	main()
{
	int count = ft_printf(" %p %p ", 0, 0);
	printf("\n COUNT %i \n", count);
	count = printf(" %p %p ", 0, 0);
	printf("\n COUNT %i \n", count);
}*/
