/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helperstwo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:51:59 by ibaaziz           #+#    #+#             */
/*   Updated: 2024/11/29 20:52:03 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putptr(unsigned long int nb, char *base)
{
	char	c;
	int		count;
	size_t	baselen;

	count = 1;
	baselen = ft_strlen(base);
	if (nb == 0)
	{
		return (ft_putstr_fd("(nil)", 1));
	}
	if (nb < baselen)
	{
		c = base[nb];
		write(1, "0x", 2);
		write(1, &c, 1);
		return (3);
	}
	count = count + putptr(nb / baselen, base);
	c = base[nb % baselen];
	write(1, &c, 1);
	return (count);
}
