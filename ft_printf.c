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
#include "libft.a"

int	ft_strlen(char *str)
{
	
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	va_start(args, str);
	ft_putstr_fd(va_arg(args, char *), 1);
	va_end(args);
	return (1);
}

int main()
{
	ft_printf("SDasdads", "bonjour");
}
