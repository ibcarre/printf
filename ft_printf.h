/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:45:07 by ibaaziz           #+#    #+#             */
/*   Updated: 2024/11/29 20:48:15 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_putnbr_fd(int nbr, int fd, int u);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *str, int fd);
int		putnbr_base(unsigned int nb, char *base);
size_t	ft_strlen(char *str);
int		putptr(unsigned long int nb, char *base);

#endif
