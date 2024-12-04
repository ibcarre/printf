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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	putnbr_base(unsigned int nb, char *base)
{
	char	c;
	int		count;
	size_t	baselen;

	count = 1;
	baselen = ft_strlen(base);
	if (nb < baselen)
	{
		c = base[nb];
		write(1, &c, 1);
		return (count);
	}
	count = count + putnbr_base(nb / baselen, base);
	c = base[nb % baselen];
	write(1, &c, 1);
	return (count);
}

/*
int	main()
{
	int b = 5;
	int *c = &b;
	int j = putptr(0, "0123456789abcdef");
	int count = printf("%p", 0);
	printf("\nTEST %i\n", j);

}*/
