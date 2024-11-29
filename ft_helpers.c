/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:39:45 by ibaaziz           #+#    #+#             */
/*   Updated: 2024/11/27 14:57:17 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putnbr_fd(int nbr, int fd, int u)
{
	long	n;
	char	c;
	int		count;

	n = nbr;
	count = 1;
	if (u)
		n = (unsigned int) nbr;
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
		return (count++);
	}
	count = count + ft_putnbr_fd(n / 10, fd, u);
	c = (n % 10) + '0';
	write(fd, &c, 1);
	return (count ++);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr_fd("(null)", 1));
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	putnbr_base(int nb, char *base)
{
	char	c;
	int		count;
	int		baselen;
	unsigned int	n;

	n = (unsigned int)nb;
	count = 1;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	baselen = ft_strlen(base);
	if (n < baselen)
	{
		c = base[n];
		write(1, &c, 1);
		return (count);
	}
	count = count + putnbr_base(n / baselen, base);
	c = base[n % baselen];
	write(1, &c, 1);
	return (count);
}

int	putptr(void *c)
{
	(void)c;
	return (1);
}

/*
int	main()
{
	putnbr_base(-1, "0123456789abcdef");
	printf("\n");
	printf("%x\n", -1);
	int count = printf("%x\n", -1);
	printf("\n%i\n", count);

}*/
