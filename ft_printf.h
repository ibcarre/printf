/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:45:07 by ibaaziz           #+#    #+#             */
/*   Updated: 2024/11/25 16:47:38 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putnbr_fd(int nbr, int fd, int u);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *str, int fd);
int	putnbr_base(int nb, char *base);
int	putptr(void *);

#endif
