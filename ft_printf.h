/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaled <khaled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:02:26 by khaled            #+#    #+#             */
/*   Updated: 2024/06/21 00:02:56 by khaled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *input, ...);
int	ft_putchar(char c);
int	ft_putint(int n);
int	ft_print_hex(unsigned int num, const char c);
int	ft_print_ptr(unsigned long long ptr);
int	ft_putunsigned(unsigned int n);
int	ft_putstr(char *s);

#endif
